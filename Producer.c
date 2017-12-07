//PRODUCER, Gabriel Lluch and Ethan Anderson
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void Producer() {

  FILE *mydata = fopen("mydata.txt", "r");
  char transfer;  
//continue while until end of file
  while(!feof(mydata)) {
    
//pull turn digit from file
    FILE *myTURN = fopen("TURN.txt", "r+");
    if (myTURN == NULL) exit(1);
    char checkTurn = getc(myTURN);
    fclose(myTURN);
//check if my turn, if so then pull char from mydata and push to DATA    
    if (checkTurn == '0') {
      transfer = getc(mydata);
      FILE *DATA = fopen("DATA.txt", "r+");
      putc(transfer, DATA);
      fclose(DATA);
//set to consumer's turn     
      FILE *yourTURN = fopen("TURN.txt", "r+");
      putc('1', yourTURN);
      fclose(yourTURN);
    }
  }
  fclose(mydata);
}
