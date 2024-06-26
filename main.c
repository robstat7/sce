#include <stdio.h>
#include <string.h>

int main(void)
{
	char cmd[100];

	while(strcmp(cmd, "q") != 0) {
		scanf("%s", cmd);
	}

	return 0;
}
