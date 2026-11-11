#include<iostream>
#include<stdio.h>
using namespace std;
bool ll(int  a,int b){
	if(a>=68&&b>=68){
		return true;
	}
	else if(a<68&&b<68){
		return true;
	}
	return false;
}
int main(void){
    
    
    freopen("travel.out", "w", stdout);
    freopen("travel.in", "r", stdin);
    
        
    

	string c1,s1,c2,s2,r1,r2;
	int a1,a2;
	cin>>c1>>s1>>c2>>s2;
	r1=s1[0]+s1[1];
	r2=s2[0]+s2[1];
	a1=(int)s1[2];
	a2=(int)s2[2];
	if(c1==c2){
		printf("1");
		if(r1==r2){
			printf("1");
			if(ll(a1,a2)){
				printf("1");
				if(a1+1==a2||a2+1==a1)printf("1");
				else printf("0");
			}
			else{
				printf("00");
			}
		}
			
		else{
			printf("000");
		}
	}
	else{
		printf("0000");
	}
	fclose(stdout);
	fclose(stdin);
	return 0;
} 
