#include<stdio.h>
#include<conio.h>
int Isleapyear(int year){
	return (year%4==0 && year%100!=0||year%400==0)?1:0;
}
int getweekday(int year){//xxxx/01/01
	int days=0;
	for(year=year-1;year>=1;year--){
		if(Isleapyear(year))days+=366;
		else days+=365;
	}
	return 1+days%7;
}

int main(){
	int date[12][6][7];
	int calendar[][12]={{31,28,31,30,31,30,31,31,30,31,30,31},{31,29,31,30,31,30,31,31,30,31,30,31}};
	int year;
	char title[]="SUN MON TUE WED THU FRI SAT";
	int sw,leap,i,j,k,wd,day;
	printf("Please input the year:");
	scanf("%d",&year);
	sw=getweekday(year);
	leap = Isleapyear(year);
	wd=sw;
	for(i=0;i<12;i++){
		day=1;
		for(j=0;j<6;j++)
			for(k=0;k<7;k++)
				if(k<wd && j==0 || day>calendar[leap][i] )date[i][j][k]=0;
				else{
					date[i][j][k]=day;
					day++;
					wd=(wd+1)%7;
				}
	}
	printf("\n|===The Calendar of Year %d ===|\n|",year);
	for(i=0;i<12;i++){
		printf("%2d  %s |\n|",i+1,title);
			for(j=0;j<6;j++){
				printf("   ");
				for(k=0;k<7;k++)
					if(date[i][j][k])
						printf("%4d",date[i][j][k]);
					else printf("    ");
					printf(" |\n|");
				}

	}
	puts("================================|");
	puts("\n Press any key to quit...");
    getch();
    return 0;

}
