#include <stdio.h>
#include <stdlib.h>

int main()
{
	int day,month,year,q,m,j,k,end_year,determining_day,determining_day_2,y,j_2,k_2,iteration;
	int total =0;
	printf("enter date  [day month year]:\n");
	scanf("%d %d %d",&day,&month,&year);
	printf("enter end year:\n");
	scanf("%d",&end_year);

	iteration = end_year - year;
	q = day;
	m = month;
	y = year;
	if(m == 1 || m ==2){
		m = m + 12;
		y--;
	}
	j = y / 100;
	k = y % 100;
	if(month == 1 || month ==3 || month ==5|| month ==7|| month ==8|| month ==10|| month ==12){
		if(day > 31 || day < 1){
			printf("date is invalid.\n");
			return EXIT_FAILURE;
		}	
	} else if(month == 2){
				if(day >28 || day<1){
	         		printf("date is invalid.\n");
			        return EXIT_FAILURE;
				}
	}else{
		if(day >30 || day<1){
			
			printf("date is invalid.\n");
			return EXIT_FAILURE;
			}
		
	}
	determining_day = (q + (13*(m+1)/5) + k + (k/4) +(j/4) +(5*j)) % 7;
	switch(determining_day){
		case 0:
			printf("it's a saturday\n");
			break;
		case 1:
			printf("it's a sunday\n");
			break;
		case 2:
			printf("It's a Monday\n");
			break;
		case 3:
			printf("it's a tuesday\n");
			break;
		case 4:
			printf("it's a wednesday\n");
			break;
		case 5:
			printf("it's a thursday\n");
			break;
		case 6:
			printf("it's a friday\n");
			break;
		default:
			break;
	}
	for(int i = 0; i < iteration ;i++){
		y++;
		j_2 = y / 100;
		k_2 = y % 100;
		determining_day_2 = (q + (13*(m+1)/5) + k_2 + (k_2/4) +(j_2/4) +(5*j_2)) % 7;
		if(determining_day == determining_day_2){
			total++;		
		}
		
	}
	printf("same day-and-month on same weekday between %d and %d:%d \n",(year+1),end_year,total);

	
	return 0;
}
