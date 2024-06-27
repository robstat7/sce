|| राम ||

|| RAAM ||

# Sataguru Code Editor

Sataguru Code Editor is a line-oriented code editor. It runs on a Unix-like operating system.

It supports two editing modes viz. command mode and input mode.

Please [check](https://github.com/robstat7/sce/releases/tag/sce-0.01) the version 0.01 release.

## Perks

It is both peaceful (read: peace of mind) and productive to use the Sataguru Code Editor than `vi` or `vim` and other full-screen (both command-line/GUI-based) editors. It is more focused and you save a lot of time that you waste on the full-screen editors. It is more focused in the sense that you need a little planning and organization before writing code.

- Peace of mind
- Productive
- More focused

## Editing Modes commands

### Command Mode commands:

- `e file` (edit file command): open a file named "file" present in the present working directory for editing. The file is read into the Sataguru text buffer.
- `,p` (print command): print the text buffer.
- `w file` (write to file command): write the text buffer to the file specified by "file" name in the present working directory. The file can either be a new or existing file.
- `q` (quit): quit the code editor program.

### Input Mode commands:
- `a` (append command): append line(s) to the text buffer. A line input is done by pressing Enter. After appending code line(s), press . (dot) followed by Enter to exit input mode (it is the . (dot) sub-command).

## Basic code editing
```bash
$ ./sce
a
#include <stdio.h>

int main(void)
{
	printf("Raam Raam sa\n");
	  
	return 0;
}
.
w raam_raam.c
78
q
$ ./sce
e raam_raam.c
78
,p
#include <stdio.h>

int main(void)
{
	printf("Raam Raam sa\n");

	return 0;
}
a

/* TODO: add a function to add two numbers and call it from the main */
.
,p
#include <stdio.h>

int main(void)
{
	printf("Raam Raam sa\n");

	return 0;
}

/* TODO: add a function to add two numbers and call it from the main */
w raam_raam.c
151
q
$ file raam_raam.c 
raam_raam.c: C source, ASCII text
```

## Compiling
```bash
$ gcc main.c -o sce
```
<br/><br/>

🙏 🌹 Raam Raam sa 🌹 🙏
