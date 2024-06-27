#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define COMMAND_MODE					0x0
#define INPUT_MODE					0x1

#define TEXT_BUFFER_MAX_LENGTH				840000		/* support for 4k lines */
#define INPUT_LINE_MAX_LENGTH				210	/* maximum no. of characters in a line */

/* the default mode when sce runs for the first time */
int editing_mode = COMMAND_MODE;

/* initialize the text buffer */
char *text_buffer = NULL;

/* declare and initialize the text buffer position variable */
int text_buffer_position = 0;

void append_command(void);
void append_to_text_buffer(char *input_line);

int main(void)
{
	char cmd[100];

	text_buffer = (char *) malloc(TEXT_BUFFER_MAX_LENGTH);

	if(text_buffer == NULL) {
		printf("error: couldn't allocate the text buffer!\n");
		return 1;
	}

	do {
		fgets(cmd, 100, stdin);

		if(strncmp(cmd, "a\n", 2) == 0) {	/* append command */
			editing_mode = INPUT_MODE;
			append_command();
			editing_mode = COMMAND_MODE;
		}
		else if(strncmp(cmd, "w ", 2) == 0)	/* write command */
		{
			char fname[50];

			/* get the filename */
			int cmd_len = strlen(cmd) - 1;		/* subtract 1 to neglect the newline character */

			for(int i = 2, j = 0; (i < cmd_len && j < 50); i++, j++) {
				fname[j] = cmd[i];
			}

			/* create or open the file in the present working directory */
			int fd = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if(fd != -1) {
				printf("%d\n", write(fd, text_buffer, text_buffer_position));
			}

			close(fd);

		}
		else if(strncmp(cmd, "e ", 2) == 0) {		/* edit file command */
			char fname[50];

			/* get the filename */
			int cmd_len = strlen(cmd) - 1;		/* subtract 1 to neglect the newline character */

			for(int i = 2, j = 0; (i < cmd_len && j < 50); i++, j++) {
				fname[j] = cmd[i];
			}

			/* open the file in the present working directory */
			int fd = open(fname, O_RDWR, 0644);
			if(fd != -1) {
				/* update the text buffer position */
				text_buffer_position = read(fd, text_buffer, TEXT_BUFFER_MAX_LENGTH);

				printf("%d\n", text_buffer_position);
			}

			close(fd);
		}
		else if(strncmp(cmd, ",p\n", 3) == 0) {		/* print command */
			/* print the text buffer */
			for(int i = 0; i < text_buffer_position; i++) {
				printf("%c", text_buffer[i]);
			}
		}
	} while(strncmp(cmd, "q\n", 2) != 0);

	free(text_buffer);

	return 0;
}

void append_command(void)
{
	char input_line[INPUT_LINE_MAX_LENGTH];

	while(1) {
		fgets(input_line, INPUT_LINE_MAX_LENGTH, stdin);

		if(strncmp(input_line, ".\n", 2) == 0) {
			break;
		}

		append_to_text_buffer(input_line);
	}

}

/* append the input line to the text buffer */
void append_to_text_buffer(char *input_line)
{
	int i, j;
	
	int input_line_len = strlen(input_line) + 1;

	for(i = text_buffer_position, j = 0; (i < TEXT_BUFFER_MAX_LENGTH && j < input_line_len); i++, j++) {
		/* skip appending the null character */
		if(input_line[j] == '\0') {
			i--;
			continue;
		}

		text_buffer[i] = input_line[j];
	}

	text_buffer_position = i;
}
