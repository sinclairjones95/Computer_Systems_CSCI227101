// count.c  Count the number of lines and chars in the input.

#include <stdio.h>

int main() {
  int lineCount = 0;
  int numLines = 0;
  int numChars = 0;
  int numWords = 0;
  int avgLength=0;
  int letterCount = 0;
  int prev = 0;  	   //tracking whether last char is a letter or a space
  printf("Enter text.  Use an empty line to stop.\n");
  
  while (1) {
      int ic = getchar();
      if (ic < 0)    //EOF (end of file) encountered
          break;
      char c = (char) ic;
      if (c == '\n' && lineCount == 0) //Empty line
          break; 

      numChars ++;      

      if (c == '\n') {  //new line
          numLines ++;
          lineCount = 0;
	  
	  if (prev==1)  //if prev was a letter
	 	 numWords++;
	  prev = 0;
      }

      else if (c == ' '){
	  if (prev==1){
	  	numWords++;
	 	prev = 0;     //prev=false
	  }
	  lineCount++;
      }
      else{                   //is a letter
          lineCount ++;
	  letterCount++;
	  prev = 1;            //prev = true
      }
  }
  
  if (numWords!=0)
  	avgLength = letterCount / numWords;		//average length  

  printf("Your text has %d lines and %d characters.\n", numLines, numChars);
  printf("Your text has %d words, with an average length of %d.\n", numWords, avgLength);	
}
