#include <stdio.h>
#include <string.h>

#define COMMAND_MODE					0x0
#define INPUT_MODE					0x1

#define LINE_LENGTH					81

/* the default mode when sce runs for the first time */
int editing_mode = COMMAND_MODE;

/* initialize text buffer */
char buffer[1000];

void append_to_buffer(void);

int main(void)
{
	char cmd[100];

	do {
		scanf("%s", cmd);

		getchar();		/* flush the stdin */

		if(strcmp(cmd, "a") == 0) {	/* append command */
			editing_mode = INPUT_MODE;
			append_to_buffer();
			editing_mode = COMMAND_MODE;
		}
	} while(strcmp(cmd, "q") != 0);

	return 0;
}

void append_to_buffer(void)
{
	char input_line[LINE_LENGTH];

	do {
		fgets(input_line, LINE_LENGTH, stdin);

	} while(strncmp(input_line, ".", 1) != 0);

}
