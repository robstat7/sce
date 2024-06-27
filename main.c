#include <stdio.h>
#include <string.h>

#define COMMAND_MODE					0x0
#define INPUT_MODE					0x1

#define TEXT_BUFFER_MAX_LENGTH				1000
#define INPUT_LINE_MAX_LENGTH				81

/* the default mode when sce runs for the first time */
int editing_mode = COMMAND_MODE;

/* initialize the text buffer */
char text_buffer[TEXT_BUFFER_MAX_LENGTH];

/* declare and initialize the text buffer position variable */
int text_buffer_position = 0;

void append_command(void);
void append_to_text_buffer(char *input_line);

int main(void)
{
	char cmd[100];

	do {
		scanf("%s", cmd);

		getchar();		/* flush the stdin */

		if(strcmp(cmd, "a") == 0) {	/* append command */
			editing_mode = INPUT_MODE;
			append_command();
			for(int i = 0; i < text_buffer_position; i++) {
				printf("%c", text_buffer[i]);
			}
			editing_mode = COMMAND_MODE;
		}
	} while(strcmp(cmd, "q") != 0);

	return 0;
}

void append_command(void)
{
	char input_line[INPUT_LINE_MAX_LENGTH];

	do {
		fgets(input_line, INPUT_LINE_MAX_LENGTH, stdin);

		append_to_text_buffer(input_line);
	} while(strncmp(input_line, ".", 1) != 0);

}

/* append the input line to the text buffer */
void append_to_text_buffer(char *input_line)
{
	int i, j;
	
	int input_line_len = strlen(input_line) + 1;

	for(i = text_buffer_position, j = 0; (i < TEXT_BUFFER_MAX_LENGTH && j < input_line_len); i++, j++) {
		text_buffer[i] = input_line[j];
	}

	text_buffer_position = i;
}
