#include<bits/stdc++.h>
using namespace std;

char c1[5],s1[5],c2[5],s2[5];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",c1,s1,c2,s2);
	if((c1[0]==c2[0])&&(c1[1]==c2[1])){
		printf("1");
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			printf("1");
			int a1=s1[2]-'A',a2=s2[2]-'A';
			if(((a1>=0&&a1<=2)&&(a2>=0&&a2<=2))||((a1>=3&&a1<=4)&&(a2>=3&&a2<=4))){
				printf("1");
				if(abs(a1-a2)==1){
					printf("1");
					return 0;
				}
				else{
					printf("0");
					return 0;
				}
			}
			else{
				printf("00");
				return 0;
			}
		}
		else{
			printf("000");
			return 0;
		}
	}
	else{
		printf("0000");
		return 0;
	}
}
