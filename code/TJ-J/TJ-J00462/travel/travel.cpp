#include<bits/stdc++.h>
using namespace std;
char s[5],s2[5],t[5],t2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",s+1,s2+1,t+1,t2+1);
	if(s[1]*10+s[2]==t[1]*10+t[2]){
		printf("1");
		if(s2[1]*10+s2[2]==t2[1]*10+t2[2]){
			printf("1");
			if((s2[3]<'D' && t2[3]<'D') || (s2[3]>'C' && t2[3]>'C') ){
				printf("1");
				if(abs(s2[3]-t2[3])==1){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	
}
