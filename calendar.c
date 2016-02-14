//calendar.c returns a calendar under the specified parameters

#include <stdio.h>


int main() {

	int numDays;
	int firstDay;
	
	printf("Enter the number of days in a month: ");
	scanf("%d", &numDays);
	
	printf("Enter starting day of the week (1=Sun, 7=Sat): ");
	scanf("%d", &firstDay);
	
	while (!(firstDay<=7 && firstDay>=1)){
		printf("The starting day must be between 1 and 7. \n");
		printf("Enter starting day of the week (1=Sun, 7=Sat): ");
		scanf("%d", &firstDay);
	}

	

	int day;
	int dayWeek;
	dayWeek=1;
	day = 2 - firstDay;

	printf("\n");
	while (day<=numDays){
		if (day>0){
				printf("%3d", day);	
				if (dayWeek%7==0)
					printf("\n");
		} 
		else {
			printf("   ");
		}

		day++;
		dayWeek++;
	}
	printf("\n");

}
