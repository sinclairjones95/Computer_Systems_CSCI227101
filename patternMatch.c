#include <stdio.h>

//use of pointers

int readline(char arr[], int length){
	
	int i=0; 
	char c;
	while (i<length && 1){
		scanf("%c",&c);

		if( c=='\n' || c=='\0')
			break;

		*(arr + i)= c;
		i++;
	}
	//printf("%d", i);
	return i;
}

char * findmatch(char pattern[], char text[], int patternlength, int textlength){
	char *p=NULL;
	int j;
	int i;
	for(i=0; i<textlength; i++){ //iterates through text
		
		for (j=0; j<patternlength; j++){ //iterates though pattern
			if( *(text+i+j) != *(pattern+j) ){
				if( *(pattern+j)!='?' ){ //j is a wild char
					break;	
				}
			}
			
		}
		if ( j==patternlength ){
			p = text+i;
			break;
		}
	}
	return p
;
}

void printmessage( char *position,char text[],int patternlength,int textlength){
	
	if(position!=NULL){	
		char *p=position;
		char x = p-text;
		int y = (int)x;

		printf("The pattern was found at char %d.", y);
		if (patternlength<(textlength-x) ){
			int i;
			printf("The remaining text chars are: ");
			for (i=0; i<(textlength-x-patternlength); i++){
				 printf("%c", *(p+patternlength+i));
			}
		
		}
		printf("\n");
	}
	else{
		printf("no match \n");
	}
}


int main() {
  char text[40], pattern[40], *position;
  int textlength, patternlength;

  printf("Enter text: ");
  textlength = readline(text, 40);
  printf("Enter pattern: ");
  patternlength = readline(pattern, 40);

  position = findmatch(pattern, text, patternlength, textlength);

  printmessage(position, text, patternlength, textlength);

}

