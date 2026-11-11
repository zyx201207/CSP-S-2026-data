#include<bits/stdc++.h>
using namespace std;
char c,s;
int c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d",&c1);
	scanf("%d",&c2);
	scanf("%s",&c);
	scanf("%d",&s1);
	scanf("%d",&s2);
	scanf("%s",&s);
	if(c1-s1==0){
		printf("1");
		if(c2==s2){
			printf("1");
			if((c=='A'||c=='B'||c=='C')&&(s=='A'||s=='B'||s=='C')){
				printf("1");
				int a,b;
				a=c;
				b=s;
				if(a-b==1||b-a==1){
					printf("1");
				}else printf("0");
			}
			else if((c=='D'||c=='F')&&(s=='D'||s=='F')){
				printf("11");
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	return 0;
}
