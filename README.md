# CPSC 4100 - Group 5 Project - Due 4/18/2018 @midnight
## TODO
* We need all of the submissions.
* We need each member to submit their page to the [report located here](https://docs.google.com/document/d/1mL7iQamNdYdcfMzy2o2aZtsb8wW4hbJQ_0H6KddiEpQ/edit?usp=sharing).
* We need to write the conclusion portion of the paper, recommending a specific language.

## TODO - Resolved.
* We will no-op invalid instructions. ~~[We need to discuss edge-cases](https://github.com/oitsjustjose/CPSC4100/issues/3).~~
* We will support draw empty box. ~~[We need to decide if we are supporting shapes.](https://github.com/oitsjustjose/CPSC4100/issues/4)~~
* No configurable board size. ~~[We need to decide if we are allowing the board size to be configurable.](https://github.com/oitsjustjose/CPSC4100/issues/5)~~
* Yes, fill will take a string and we use the first character of that string. ~~[Do we allow the fill-character to be specified?](https://github.com/oitsjustJose/CPSC4100/issues/6)~~
* We will add simple running instructions, into each subfolder. ~~[Instructions for usage / professor.](https://github.com/oitsjustjose/CPSC4100/issues/7)~~

## [Report - Google Docs](https://docs.google.com/document/d/1mL7iQamNdYdcfMzy2o2aZtsb8wW4hbJQ_0H6KddiEpQ/edit?usp=sharing)
Each group is responsible for turning in a single PDF file containing the following items:
1. One overview page describing their problem and listing the languages used.
2. Approximately one or two pages per language, describing the language and approach to solving the problem.
Include the following items:

* What distinguishes this language from the others used
* What were any perceived benefits or problems experienced using this language for the solution.

3. In conclusion, a supported recommendation for what language to use for this and similar problems.
4. An appendix, organized by language, containing all source code and screenshots of the programs running.

## Assignment
Each team member must submit a solution in a different programming language. The output and functionality of each program must match.

Your program will read in a sequence of “instructions” and generate an output text containing ascii art described by these instructions. You get to decide on the complexity of the output art and the functionality of the instructions, but all programs must be able to process the same input.

You must be able to at least draw vertical and horizontal straight lines, and fill closed regions with a given text character.

## Languages
* Joshua Freeman - C
* Jose Stovall - **Python (Done)**
* Colby Myers
* Aaron Boggs - **Ruby (Done)**
* Nicholas Haymore - **PHP (Done)**

## Instructions
These are read-in from a text-file in the root of this repository: `instructions.txt`. Each of our programs should read from this file and produce their output. We support the following instructions:

NOTE! Some of the instructions have outstanding TODOs, please reference the top of this README for more information.

### Invalid instructions
Any invalid instructions, or instructions that result in invalid operations are simply noop'd. That is, they do not halt the program, but instead fail silently - letting further instructions continue.

Example: `draw_horizontal_line -10, -100, 40`

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
Sets characters on board to the first character of string.
We are using a simple [flood-fill algorithm](https://en.wikipedia.org/wiki/Flood_fill) to implement this feature, [here is a good reference](https://en.wikipedia.org/wiki/Flood_fill).
`fill, x_cord, y_cord, string`

It's worth noting that this fill command should be able to take in a **string** of any length and only get the **first** character of that string (meaning if it's a string of length 1, we're good, but if someone types in "@%&#^", then only @ is printed)

### draw\_empty\_box
Draws a box-like shape on the board with `#` characters.
The center of the box is **not** filled in with any character.
`draw_empty_box, x_cord, y_cord, width, height`

## Example Output
There is a text-file, `example_out.txt` in the root of this repository which we can compare each other's output against. There are several online tools you can use to easily compare your output vs. our group's expected output:

* https://text-compare.com/
* https://www.diffchecker.com/

Or linux command line:
`diff output1 output2`
