#include<bits/stdc++.h>
using namespace std;
typedef int ll;
char a1[10],a2[10],b1[10],b2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",a1+1,a2+1,b1+1,b2+1);
	ll c1=0,c2=0;
	for(int i=1;i<=2;i++){
		c1=c1*10+(a1[i]-'0');
	}
	for(int i=1;i<=2;i++){
		c2=c2*10+(b1[i]-'0');
	}
	ll d1=0,d2=0;
	for(int i=1;i<=2;i++){
		d1=d1*10+(a2[i]-'0');
	}
	for(int i=1;i<=2;i++){
		d2=d2*10+(b2[i]-'0');
	}
	if(c1==c2){
		printf("1");
		if(d1==d2){
			printf("1");
			ll u=a2[3]-'A'+1;
			ll v=b2[3]-'A'+1;
			if((u<=3&&v<=3)||(u>3&&v>3)){
				printf("1");
				if(abs(u-v)==1){
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
	return 0;
}
