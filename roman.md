# Roman Numeral Converter

A simple command-line tool that converts decimal numbers to Roman numerals.

## Overview

This C++ program takes a single integer as input and outputs the corresponding Roman numeral representation to stdout.

## Features

- Converts integers from 1 to 3999 to Roman numerals
- Input validation with helpful error messages
- Efficient greedy algorithm for conversion
- Proper error handling for invalid inputs

## Building

Compile the program using:

```bash
g++ -o roman roman.cpp
```

Or with additional compiler flags:

```bash
g++ -std=c++11 -Wall -Wextra -o roman roman.cpp
```

## Usage

```bash
./roman <number> [--ascii|-a] [--style=<style>]
./roman -h | --help
./roman -v | --version
```

### Arguments

- `<number>`: Required. The integer to convert (1-3999)
- `-h, --help`: Show help message and exit
- `-v, --version`: Show version information and exit
- `--ascii` or `-a`: Optional. Display output as ASCII art
- `--style=<style>`: Optional. Specify ASCII art style (block, minimal, fancy, outline)

### Examples

```bash
./roman 1994
# Output: MCMXCIV

./roman 49
# Output: XLIX

./roman 3999
# Output: MMMCMXCIV

./roman 1
# Output: I

./roman --help
# Shows detailed help information

./roman -h
# Same as above

./roman --version
# Output: Roman Numeral Converter v1.0

./roman -v
# Same as above
```

### ASCII Art Modes

Use the `--ascii` or `-a` flag to display Roman numerals as ASCII art. You can combine it with `--style=<style>` to choose different visual styles.

#### Available Styles

- **block** - Block letters with pipes and slashes (default)
- **minimal** - Single character representation
- **fancy** - Decorative with box drawing characters
- **outline** - Bordered character style

#### Examples by Style

```bash
./roman 5 --ascii --style=block
# Output (block style):
# |   |
# |   |
#  \_/

./roman 5 --ascii --style=minimal
# Output (minimal style):
#  V
#  V
#  V

./roman 5 --ascii --style=fancy
# Output (fancy style, with box drawing chars):
# │   │ 
# │   │ 
#  ╲ ╱

./roman 4 --ascii --style=fancy
# Output (IV with spacing):
#  │   │   │ 
#  │   │   │ 
#  │    ╲ ╱

./roman 5 --ascii --style=outline
# Output (outline style):
# ┌─┐
# │V│
# └─┘

./roman 14 -a --style=block
# Output:
#  \   /   |||  |   |  
#   \ /    |||  |   |  
#  / \    |||   \_/
```

## Input Constraints

- Minimum: 1
- Maximum: 3999

Numbers outside this range will result in an error message.

## Error Handling

The program checks for:
- Missing or invalid number argument
- Non-numeric input
- Numbers outside the valid range (1-3999)

Invalid input results in an error message printed to stderr.

## License

This project is licensed under the MIT License - see the source file for details.

## Algorithm

The conversion uses a greedy algorithm with pairs of values and their corresponding Roman numeral symbols. It iterates through the values in descending order, subtracting from the input number and appending the corresponding symbols until the number is reduced to zero.

### Symbol Values

| Symbol | Value |
|--------|-------|
| I      | 1     |
| V      | 5     |
| X      | 10    |
| L      | 50    |
| C      | 100   |
| D      | 500   |
| M      | 1000  |

The algorithm also handles subtractive notation (e.g., IV for 4, IX for 9, XL for 40, etc.)

## ASCII Art Styles Reference

The `--style` parameter allows you to choose different visual representations for ASCII art output. Here's what each style provides:

### Block Style (default)
Block letters using pipes (`|`), slashes (`\`, `/`), and underscores. Best for simplicity and compatibility.

Example symbols:
- I: Three vertical pipes
- V: V-shaped bracket
- X: X-shaped crosses
- M: M-shaped peaks

### Minimal Style
Single character representation using just the letter itself. Most compact and readable.

Example symbols:
- I, V, X, L, C, D, M: Repeated 3 times vertically

### Fancy Style
Decorative style using Unicode box-drawing characters. Each character is clearly spaced for better readability.

Example symbols:
- I: Single vertical line with spacing
- V: Vertical sides with pointed bottom
- X: X-shaped with crossing diagonals
- L, C, D, M: Box-drawn geometric shapes

### Outline Style
Bordered character style with each symbol enclosed in a box using box-drawing characters. Clean and professional appearance.

Example symbols:
- Each character surrounded by a box border

**Note:** All ASCII art styles now include spacing between individual characters for improved readability.
