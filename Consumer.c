//Ethan Anderson and Gabriel Lluch
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Consumer()
{
	while(1)
	{
		FILE *myturn = fopen("TURN.txt", "r+");
		char check = getc(myturn);
		fclose(myturn);
		
		/*checks if it is the consumer's turn*/
		if(check == '1')
		{
			FILE *data = fopen("DATA.txt","r");
			char input = getc(data);
			
			if(input == EOF)
			{
				puts("");
				break;
			}
	
			printf("%c", input);
			fflush(stdout);
			FILE *yourturn = fopen("TURN.txt", "r+");
			putc('0', yourturn);
			fclose(yourturn);
		}
	}
exit(0);
}
