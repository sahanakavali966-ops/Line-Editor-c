# Line-Editor-c
# Activity 7 - Simple Line Editor in C

## Project Description
A simple command-line Line Editor developed using C programming.
It allows users to create, modify, display, save and load a text document.

## Student Details
- Name: Sahana K
- Team Size: 1

## Data Structure
Array of strings.

```c
char lines[100][256];
int count = 0;
```

## Features Implemented
1. Insert a line
2. Delete a line
3. Display document
4. Save document to a file
5. Load document from a file

## Commands
- i n text - Insert a line
- d n - Delete a line
- p - Display document
- s filename - Save file
- l filename - Load file
- q - Quit

## Software Requirements
- Visual Studio Code
- GCC Compiler
- Windows Operating System

## How to Compile
gcc line_editor.c -o line_editor.exe

## How to Run
.\line_editor.exe

## Project Files
- line_editor.c - Main C source code
- HELP.md - User guide
- README.md - Project documentation
- document.txt - Saved document

## Conclusion
The Simple Line Editor was successfully developed using C.
It demonstrates the use of arrays, functions, loops and file handling.
