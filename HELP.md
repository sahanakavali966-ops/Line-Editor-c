
# SIMPLE LINE EDITOR - HELP FILE

## Introduction
Simple Line Editor is a command-line text editor developed using C programming.
It allows users to insert, delete, display, save and load text lines.

## Available Commands

### 1. Insert Line
Command: i n text

Inserts text at the specified line number.

Example:
i 1 Hello

Output:
Line inserted successfully!

### 2. Delete Line
Command: d n

Deletes the specified line number.

Example:
d 2

Output:
Line deleted successfully!

### 3. Display Document
Command: p

Displays all document lines with line numbers.

Example:
p

### 4. Save File
Command: s filename

Saves all document lines into a text file.

Example:
s document.txt

### 5. Load File
Command: l filename

Loads previously saved lines from a text file.

Example:
l document.txt

### 6. Quit
Command: q

Exits the Line Editor.

## Compilation
gcc line_editor.c -o line_editor.exe

## Execution
.\line_editor.exe
