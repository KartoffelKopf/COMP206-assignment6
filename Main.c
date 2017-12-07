//Gabriel Lluch and Ethan Anderson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Producer();
void Consumer();
int main() {

//create TURN.txt file and initialize to Producer's turn
  FILE *TURN = fopen("TURN.txt", "w+");
  if (TURN == NULL) { exit(1); }
  fputc('0', TURN);
  fclose(TURN);
//Create DATA.txt
  FILE *DATA = fopen("DATA.txt", "w");
  if (DATA == NULL) { exit(1); }      
  fclose(DATA);

//fork Producer as child and Consumer as parent
  int pid;
  pid = fork();

  if (pid == -1) exit(1);
  if (pid == 0) Producer();
  if (pid != 0) Consumer();

  return 0;
}

