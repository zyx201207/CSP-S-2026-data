#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s1[5],s2[5];
	scanf("%d",&c1);
	for(int i=1;i<=4;i++)
		scanf("%c",&s1[i]);
	scanf("%d",&c2);
	for(int i=1;i<=4;i++)
		scanf("%c",&s2[i]);
	if(c1==c2){
		printf("1");
		if((s1[2]==s2[2])&&(s1[3]==s2[3])){
			printf("1");
			if(s1[4]<='C'&&s2[4]<='C'){
				printf("1");
				if((s1[4]-s2[4]==1) || (s2[4]-s1[4]==1))
					printf("1");
				else printf("0");
			}
			else if(s1[4]>='D'&&s2[4]>='D')	
				printf("11");
			else printf("00");
			}
		else {
			printf("000");
		}
	}
	else printf("0000");
	return 0;
}
