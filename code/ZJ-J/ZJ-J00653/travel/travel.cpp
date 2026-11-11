#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1[2],b1[3],a2[2],b2[3];
	scanf("%s%s%s%s",a1+1,b1+1,a2+1,b2+1);
	if(a1[1]==a2[1]&&a1[2]==a2[2]){
		printf("1");
		if(b1[1]==b2[1]&&b1[2]==b2[2]){
			printf("1");
			if((b1[3]=='A'||b1[3]=='B'||b1[3]=='C')&&(b2[3]=='A'||b2[3]=='B'||b2[3]=='C')||((b1[3]=='D'||b1[3]=='E')&&(b2[3]=='D'||b2[3]=='E'))){
				printf("1");
				if(b1[3]==b2[3]+1||b1[3]==b2[3]-1)printf("1");
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	else printf("0000");
	return 0;
}
