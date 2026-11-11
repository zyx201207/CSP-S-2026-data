#include<bits/stdc++.h>
using namespace std;
int cr,cx,r,x,r1,x1;
char a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&cr,&r,&a,&cx,&x,&b);
	r1=a-'A';x1=b-'A';
	if(r1==5) r1=4;
	if(x1==5) x1=4;
	if(cr!=cx)printf("0000\n");
	else{
		printf("1");
		if(r==x){
			printf("1");
			if((x1<3&&r1<3)||(x1>2&&r1>2)){
				printf("1");
				if(r1+1==x1||x1+1==r1) printf("1");
				else printf("0");
			}
			else printf("00");
		}else printf("000");
	}
	return 0;
}
