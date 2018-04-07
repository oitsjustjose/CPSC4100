# frozen_string_literal: true

class Point
  attr_reader :x, :y

  def initialize(x:, y:, board:)
    @x = x
    @y = y
    @board = board
  end

  def move_left
    Point.new(x: @x - 1, y: @y, board: @board)
  end

  def move_right
    Point.new(x: @x + 1, y: @y, board: @board)
  end

  def move_up
    Point.new(x: @x, y: @y - 1, board: @board)
  end

  def move_down
    Point.new(x: @x, y: @y + 1, board: @board)
  end

  def background?
    @board.background?(point: self)
  end

  def valid?
    @board.valid_point?(point: self) && background?
  end

  def set(char:)
    return unless valid?
    @board.change_at(point: self, char: char)
  end
end

module Drawable
  DIAGONAL_CHAR = {
    right: '\\',
    left: '/',
  }.freeze

  def fill(point:, char:)
    return unless point.background?

    processing_queue = [point]
    until processing_queue.empty?
      point = processing_queue.pop
      west_node = point.dup
      east_node = point.dup

      west_node = west_node.move_left while west_node.move_left.valid?
      east_node = east_node.move_right while east_node.move_right.valid?

      (west_node.x..east_node.x).each do |x|
        target = Point.new(x: x, y: west_node.y, board: self)
        target.set(char: char)

        processing_queue.push(target.move_up) if target.move_up.valid?
        processing_queue.push(target.move_down) if target.move_down.valid?
      end
    end
  end

  def draw_horizontal_line(length:, point:)
    mover = point.dup
    length.times do |x_offset|
      mover.set(char: '-')
      mover = mover.move_right
    end
  end

  def draw_vertical_line(length:, point:)
    mover = point.dup
    length.times do |y_offset|
      mover.set(char: '|')
      mover = mover.move_down
    end
  end

  def draw_diagonal_line(length:, point:, direction:)
    diagonal_point = point.dup
    length.times do
      diagonal_point = diagonal_point.send("move_#{direction}").move_down
      diagonal_point.set(char: DIAGONAL_CHAR[direction])
    end
  end
end

class Board
  include Drawable

  attr_reader :height, :width, :background_char, :board

  def initialize(height: 100, width: 100, background_char: ' ')
    @height = height
    @width = width
    @background_char = background_char

    @west_boundry = 0
    @north_boundry = 0
    @east_boundry = @width - 1
    @south_boundry = @height - 1

    @board ||= Array.new(@height) { Array.new(@width, @background_char) }
  end

  def to_s
    @board.map(&:join).join("\n")
  end

  def valid_point?(point:)
    (@west_boundry..@east_boundry).cover?(point.x) &&
      (@north_boundry..@south_boundry).cover?(point.y)
  end

  def change_at(point:, char:)
    @board[point.y][point.x] = char
  end

  def background?(point:)
    @board[point.y][point.x] == @background_char
  end
end

class Constructor
  attr_reader :game_board

  def initialize(file:)
    @game_board = Board.new(height: 32, width: 32)

    process_instructions(file)
  end

  private

  def process_instructions(file)
    File.read(file).each_line do |instruction|
      command, *args = instruction.delete(',').split
      send(command, *args)
    end
  end

  def draw_horizontal_line(x, y, length)
    @game_board.draw_horizontal_line(length: length.to_i, point: point(x.to_i, y.to_i))
  end

  def draw_vertical_line(x, y, length)
    @game_board.draw_vertical_line(length: length.to_i, point: point(x.to_i, y.to_i))
  end

  def draw_diagonal_line(x, y, length, direction)
    @game_board.draw_diagonal_line(length: length.to_i, point: point(x.to_i, y.to_i), direction: direction.to_sym)
  end

  def fill(x, y)
    @game_board.fill(point: point(x.to_i, y.to_i), char: '@')
  end

  def draw_filled_box(*args)
  end

  def draw_empty_box(*args)
  end

  def point(x, y)
    Point.new(x: x, y: y, board: @game_board)
  end
end

puts Constructor.new(file: '../instructions.txt').game_board
