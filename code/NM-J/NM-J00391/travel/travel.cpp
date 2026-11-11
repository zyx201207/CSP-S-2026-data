#include<bits/stdc++.h>
#define intl long long
using namespace std;
char s11,s12,s13,s21,s22,s23;
int c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
char s11,s12,s13,s21,s22,s23;
scanf("%d",&c1);
scanf(" %c%c%c",&s11,&s12,&s13);
scanf("%d",&c2);
scanf(" %c%c%c",&s21,&s22,&s23);
if(c1==c2){
	printf("1");
}else{
	printf("0000");
	return 0;
}
if(s11==s21 and s22==s12){
	printf("1");
}else{
	printf("000");
	return 0;
}
if(s13=='A' || s13=='B' || s13=='C'){
	if(s23=='A'|| s23=='B'|| s23=='C'){
		printf("1");
	}
	else{
		printf("00");
		return 0;
	}
}
if(s13=='D' || s13=='F'){
	if(s23=='D'|| s23=='F'){
		printf("1");
	}
	else{
		printf("00");
		return 0;
	}
}
if(s13=='A'|| s23=='B'){
	printf("1");
	return 0;
}else if(s13=='B'){
	if(s23=='A'|| s23=='C'){
		printf("1");
		return 0;
	}
	}else if(s13=='C'){
		if(s23=='B'){
			printf("1");
			return 0;
		}
	}else if(s13=='D'|| s23=='F'){
	printf("1");
	return 0;
}else if(s13=='F'|| s23=='D'){
	printf("1");
	return 0;
}
printf("0");	
return 0;
}
