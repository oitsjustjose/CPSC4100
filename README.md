# CPSC 4100 - Group 5 Project
## TODO
* We need all of the submissions.
* [We need to discuss edge-cases](https://github.com/oitsjustjose/CPSC4100/issues/3).
* [We need to decide if we are supporting shapes.](https://github.com/oitsjustjose/CPSC4100/issues/4)
* [We need to decide if we are allowing the board size to be configurable.](https://github.com/oitsjustjose/CPSC4100/issues/5)
* [Do we allow the fill-character to be specified?](https://github.com/oitsjustjose/CPSC4100/issues/6)
* [Instructions for usage / professor.](https://github.com/oitsjustjose/CPSC4100/issues/7)

## Assignment
Each team member must submit a solution in a different programming language. The output and functionality of each program must match.

Your program will read in a sequence of “instructions” and generate an output text containing ascii art described by these instructions. You get to decide on the complexity of the output art and the functionality of the instructions, but all programs must be able to process the same input.

You must be able to at least draw vertical and horizontal straight lines, and fill closed regions with a given text character.

## Languages
* Joshua Freeman
* Jose Stovall - **Python (Done)**
* Colby Myers
* Aaron Boggs - **Ruby (Done)**
* Nicholas Haymore

## Instructions
These are read-in from a text-file in the root of this repository: `instructions.txt`. Each of our programs should read from this file and produce their output. We support the following instructions:

NOTE! Some of the instructions have outstanding TODOs, please reference the top of this README for more information.

### Board
Currently hardcoded to be 32x32 size. Prefilled with a character of ` ` (space).

### draw\_horizontal\_line
Sets characters on board to `-`
`draw_hoizontal_line, x_cord, y_cord, length`

### draw\_vertical\_line
Sets characters on board to `|`
`draw_vertical_line, x_cord, y_cord, length`

### draw\_diagonal\_line
Sets characters on board to `\` for `direction==right`
Sets characters on board to `/` for `direction==left`
`draw_diagonal_line, x_cord, y_cord, length, direction`

### fill
Sets characters on board to `@`.
We are using a simple [flood-fill algorithm](https://en.wikipedia.org/wiki/Flood_fill) to implement this feature, [here is a good reference](https://en.wikipedia.org/wiki/Flood_fill).
`fill, x_cord, y_cord, char`
It's worth noting that this fill command should be able to take in a **string** of any length and only get the **first** character of that string (meaning if it's a string of length 1, we're good, but if someone types in "@%&#^", then only @ is printed)

## Example Output
There is a text-file, `example_out.txt` in the root of this repository which we can compare each other's output against. There are several online tools you can use to easily compare your output vs. our group's expected output:

* https://text-compare.com/
* https://www.diffchecker.com/

Or linux command line:
`diff output1 output2`

## Edge Cases
## Usage
