import os
import sys

grid = [[" " for x in range(32)] for y in range(32)] 


def print_err(cmd):
	print("Command: "+cmd+" not found")


def print_grid():
	global grid
	for row in grid:
		row_text = ""
		for col in row:
			row_text += col
		print(row_text)


def draw_filled_box(x, y, w, h):
	global grid
	# No-Op invalid inputs:
	if x < 0 or y < 0 or w < 1 or h < 1:
		return
	if y > len(grid) or x > len(grid[0]) or (y + w) > len(grid) or (x + h)  > len(grid[0]):
		return
	tally = 0
	# Draw the filled box:
	for i in range(h):
		for j in range(w):
			grid[y + j][x + i] = '#'


def draw_empty_box(x, y, w, h):
	global grid
	# No-Op invalid inputs:
	if x < 0 or y < 0 or w < 1 or h < 1:
		return
	if y > len(grid) or x > len(grid[0]) or (y + w) > len(grid) or (x + h)  > len(grid[0]):
		return
	# Draw the box:
	for i in range(h):
		# If it's the top or bottom:
		for j in range(w):
			if i == 0 or i == h - 1:
				grid[y + j][x + i] = '#'
		# It's not the top or bottom:
			elif j == 0 or j == w - 1:
				grid[y + j][x + i] = '#'
		print("")


def draw_diagonal(x, y, size, dir):
	global grid
	# No-Op invalid inputs:
	if x < 1 or y < 1 or size < 1 or y + size > len(grid) or x + size > len(grid[0]):
		return
	if "right" in dir:
		i = 0
		while i < size:
			j = size
			while j >= 0:
				if i == j:
					grid[y + j][x - i] = '/'
				j -= 1
			i += 1
	else:
		for i in range(size):
			for j in range(size):
				if i == j:
					grid[y + j][x + i] = '\\'


def draw_vertical(x, y, size):
	global grid
	# No-Op invalid inputs:
	if x < 1 or y < 1 or size < 1 or y + size > len(grid):
		return
	for i in range(size):
		grid[y + i][x] = "|"


def draw_horizontal(x, y, size):
	global grid
	# No-Op invalid inputs:
	if x < 1 or y < 1 or size < 1 or x + size > len(grid[0]):
		return
	# Print them (and a newline):
	for i in range(size):
		grid[y][x + i] = "-"


def fill(x, y, char):
	global grid
	# No-Op invalid inputs:
	if x < 1 or y < 1:
		return
	if grid[y][x] == " ":
		grid[y][x] = char
	try:
		if grid[y - 1][x] == " ":
			fill(x, y - 1, char)
	except IndexError:
		pass
	try:
		if grid[y + 1][x] == " ":
			fill(x, y + 1, char)
	except IndexError:
		pass
	try:
		if grid[y][x - 1] == " ":
			fill(x - 1, y, char)
	except IndexError:
		pass
	try:
		if grid[y][x + 1] == " ":
			fill(x + 1, y, char)
	except IndexError:
		pass


def main():
	file = open("../instructions.txt", "r")
	for cmd in file.readlines():
		parts = cmd.lower().replace(" ", "").split(",")
		# Expecting draw_horizontal_line, x, y, size
		if "draw_horizontal_line" in parts[0] and len(parts) == 4:
			draw_horizontal(int(parts[1]), int(parts[2]), int(parts[3]))
		# Expecting draw_vertical_line, x, y, size
		elif "draw_vertical_line" in parts[0] and len(parts) == 4:
			draw_vertical(int(parts[1]), int(parts[2]), int(parts[3]))
		# Expecting draw_diagonal_line, x, y, size, dir
		elif "draw_diagonal_line" in parts[0] and len(parts) == 5:
			draw_diagonal(int(parts[1]), int(parts[2]), int(parts[3]), parts[4])
		# Expecting draw_empty_box, x, y, w, h
		elif "draw_empty_box" in parts[0] and len(parts) == 5:
			draw_empty_box(int(parts[1]), int(parts[2]), int(parts[3]), int(parts[4]))
		# Expecting draw_filled_box, x, y, w, h
		elif "draw_filled_box" in parts[0] and len(parts) == 5:
			draw_filled_box(int(parts[1]), int(parts[2]), int(parts[3]), int(parts[4]))
		# Expecting fill, x, y, char
		elif "fill" in parts[0] and len(parts) == 4:
			fill(int(parts[1]), int(parts[2]), parts[3][0])
		else:
			print_err(cmd)
	print_grid()


if __name__ == "__main__":
	main()

