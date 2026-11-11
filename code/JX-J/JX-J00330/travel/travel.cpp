#include<bits/stdc++.h>
using namespace std;
char rx[11],rw[11],xx[11],xw[11];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",rx,rw,xx,xw);
	if((rx[0]-'0')*10+rx[1]-'0'==(xx[0]-'0')*10+xx[1]-'0'){
		printf("1");
		if((rw[0]-'0')*10+rw[1]-'0'==(xw[0]-'0')*10+xw[1]-'0'){
			printf("1");
			if((rw[2]<='C'&&xw[2]<='C')||(rw[2]>='D'&&xw[2]>='D')){
				printf("1");
				if((rw[2]-xw[2]==1&&rw[2]!='D')||(xw[2]-rw[2]==1&&xw[2]!='D')||(rw[2]=='F'&&xw[2]=='D')||(rw[2]=='D'&&xw[2]=='F')){
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
