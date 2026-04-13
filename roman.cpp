/*
 * MIT License
 *
 * Copyright (c) 2026
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <map>

using namespace std;

const string VERSION = "1.0";

// Enum for ASCII art styles
enum class AsciiStyle {
    BLOCK,
    MINIMAL,
    FANCY,
    OUTLINE
};

string convertToRoman(int num) {
    // Vector of pairs: (value, roman numeral symbol)
    vector<pair<int, string>> romanValues = {
        {1000, "M"},
        {900, "CM"},
        {500, "D"},
        {400, "CD"},
        {100, "C"},
        {90, "XC"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}
    };

    string result = "";

    for (const auto& pair : romanValues) {
        while (num >= pair.first) {
            result += pair.second;
            num -= pair.first;
        }
    }

    return result;
}

map<char, vector<string>> getBlockStyle() {
    return {
        {'I', {" ||| ", " ||| ", " ||| "}},
        {'V', {"|   | ", "|   | ", " \\_/  "}},
        {'X', {"\\   / ", " \\ /  ", " / \\  "}},
        {'L', {"|      ", "|      ", "|_____ "}},
        {'C', {" _____ ", "|      ", "|_____ "}},
        {'D', {" __    ", "|  \\   ", "|__/   "}},
        {'M', {"|\\   /|", "| \\ / |", "|  V  |"}}
    };
}

map<char, vector<string>> getMinimalStyle() {
    return {
        {'I', {" I ", " I ", " I "}},
        {'V', {" V ", " V ", " V "}},
        {'X', {" X ", " X ", " X "}},
        {'L', {" L ", " L ", " L "}},
        {'C', {" C ", " C ", " C "}},
        {'D', {" D ", " D ", " D "}},
        {'M', {" M ", " M ", " M "}}
    };
}

map<char, vector<string>> getFancyStyle() {
    return {
        {'I', {" │ ", " │ ", " │ "}},
        {'V', {"│   │", "│   │", " ╲ ╱ "}},
        {'X', {"╲ ╱", " X ", "╱ ╲"}},
        {'L', {"╔  ", "║  ", "╚══"}},
        {'C', {"╔══", "║  ", "╚══"}},
        {'D', {"╔═╗", "║ ║", "╚═╝"}},
        {'M', {"╔═╗", "║M║", "╚═╝"}}
    };
}

map<char, vector<string>> getOutlineStyle() {
    return {
        {'I', {"┌─┐", "│I│", "└─┘"}},
        {'V', {"┌─┐", "│V│", "└─┘"}},
        {'X', {"┌─┐", "│X│", "└─┘"}},
        {'L', {"┌─┐", "│L│", "└─┘"}},
        {'C', {"┌─┐", "│C│", "└─┘"}},
        {'D', {"┌─┐", "│D│", "└─┘"}},
        {'M', {"┌─┐", "│M│", "└─┘"}}
    };
}

vector<string> getRomanAsciiArt(char symbol, AsciiStyle style) {
    map<char, vector<string>> styleMap;
    
    switch (style) {
        case AsciiStyle::BLOCK:
            styleMap = getBlockStyle();
            break;
        case AsciiStyle::MINIMAL:
            styleMap = getMinimalStyle();
            break;
        case AsciiStyle::FANCY:
            styleMap = getFancyStyle();
            break;
        case AsciiStyle::OUTLINE:
            styleMap = getOutlineStyle();
            break;
    }
    
    if (styleMap.find(symbol) != styleMap.end()) {
        return styleMap[symbol];
    }
    
    return {"", "", ""};
}

void printRomanAscii(const string& roman, AsciiStyle style) {
    vector<string> lines(3, "");
    
    for (char c : roman) {
        vector<string> charArt = getRomanAsciiArt(c, style);
        for (int i = 0; i < 3; i++) {
            lines[i] += charArt[i] + " ";
        }
    }
    
    for (const auto& line : lines) {
        cout << line << endl;
    }
}

AsciiStyle parseStyle(const string& styleStr) {
    if (styleStr == "block") return AsciiStyle::BLOCK;
    if (styleStr == "minimal") return AsciiStyle::MINIMAL;
    if (styleStr == "fancy") return AsciiStyle::FANCY;
    if (styleStr == "outline") return AsciiStyle::OUTLINE;
    return AsciiStyle::BLOCK;  // Default
}

void printAvailableStyles() {
    cout << "Available ASCII styles:" << endl;
    cout << "  block    - Block letters with pipes and slashes" << endl;
    cout << "  minimal  - Single character representation" << endl;
    cout << "  fancy    - Decorative with box drawing characters" << endl;
    cout << "  outline  - Bordered character style" << endl;
}

void printHelp(const char* programName) {
    cout << "Roman Numeral Converter v" << VERSION << endl;
    cout << endl;
    cout << "Usage:" << endl;
    cout << "  " << programName << " <number> [options]" << endl;
    cout << "  " << programName << " -h | --help" << endl;
    cout << "  " << programName << " -v | --version" << endl;
    cout << endl;
    cout << "Arguments:" << endl;
    cout << "  <number>    The integer to convert (1-3999)" << endl;
    cout << endl;
    cout << "Options:" << endl;
    cout << "  -h, --help          Show this help message" << endl;
    cout << "  -v, --version       Show version information" << endl;
    cout << "  -a, --ascii         Display output as ASCII art" << endl;
    cout << "  --style=<style>     Specify ASCII art style (default: block)" << endl;
    cout << endl;
    printAvailableStyles();
    cout << endl;
    cout << "Examples:" << endl;
    cout << "  " << programName << " 1994" << endl;
    cout << "  " << programName << " 49 --ascii" << endl;
    cout << "  " << programName << " 5 --ascii --style=fancy" << endl;
}

int main(int argc, char* argv[]) {
    // Check for version flag first
    if (argc >= 2 && (string(argv[1]) == "-v" || string(argv[1]) == "--version")) {
        cout << "Roman Numeral Converter v" << VERSION << endl;
        return 0;
    }

    // Check for help flag first
    if (argc >= 2 && (string(argv[1]) == "-h" || string(argv[1]) == "--help")) {
        printHelp(argv[0]);
        return 0;
    }

    // Check if an argument was provided
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <number> [--ascii|-a] [--style=<style>]" << endl;
        cerr << "Number should be between 1 and 3999" << endl;
        cerr << "Use -h or --help for detailed help" << endl;
        return 1;
    }

    bool asciiMode = false;
    AsciiStyle style = AsciiStyle::BLOCK;
    int num;

    // Parse flags
    for (int i = 2; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--ascii" || arg == "-a") {
            asciiMode = true;
        } else if (arg.find("--style=") == 0) {
            string styleStr = arg.substr(8);  // Extract style after "--style="
            style = parseStyle(styleStr);
        }
    }

    // Parse the input
    try {
        num = stoi(argv[1]);
    } catch (const exception& e) {
        cerr << "Error: Invalid number" << endl;
        return 1;
    }

    // Validate range
    if (num < 1 || num > 3999) {
        cerr << "Error: Number must be between 1 and 3999" << endl;
        return 1;
    }

    // Convert to Roman numerals
    string roman = convertToRoman(num);

    // Output
    if (asciiMode) {
        printRomanAscii(roman, style);
    } else {
        cout << roman << endl;
    }

    return 0;
}
