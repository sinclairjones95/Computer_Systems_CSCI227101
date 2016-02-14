#include <stdio.h>
void f();

//buffer overflow

int main() {
    printf("In main...\n");
    char c = 'A';
    int n = 123;
    f();
    printf("Back in main.\n");
    printf("%d%c \n", n, c);
}

void f() {
	
    printf("In f...\n");
    // new code
	int x;
	char y;


	int *p = (&x+14);  //changing addresses (14*4) bit from int n
	char *q = (&y+56);


	*p = 666;
	*q = 'B';
}

