#include<bits/stdc++.h>
using namespace std;
char c1[5],s1[5],c2[5],s2[5];
int a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	scanf("%c%c%c%c",&c1,&s1,&c2,&s2);
	
	a = s1[3];
	b = s2[3];
	
	if(c1[1] == c2[1]&&c1[2] == c2[2]){
		printf("1");
		if(s1[1] == s2[1] &&s1[2] == s2[2]){
			printf("1");
			if(((a == 'D'|| a == 'F')&&(b =='D' || b =='F' ))||((a == 'A'|| a == 'B' || a == 'C')&&(b =='A' || b =='B' || b == 'C'))){
				printf("1");
				if(a - b == 1 || b - a == 1){
					printf("1");
				}
				else{
					printf("0");
				}
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
	
	//printf("\n\n\n\n%d\n",clock());
	return 0;
}
