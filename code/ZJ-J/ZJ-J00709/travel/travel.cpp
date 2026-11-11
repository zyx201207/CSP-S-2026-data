#include<bits/stdc++.h>
using namespace std;
char rc[3],rs[4],xc[3],xs[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s %s %s %s",rc+1,rs+1,xc+1,xs+1);
	if(rc[1]==xc[1]&&rc[2]==xc[2]){
		printf("1");
		if(rs[1]==xs[1]&&rs[2]==xs[2]){
			printf("1");
			if((rs[3]=='A'&&xs[3]=='B')||(rs[3]=='A'&&xs[3]=='C')||(rs[3]=='B'&&xs[3]=='C')||(rs[3]=='B'&&xs[3]=='A')||(rs[3]=='C'&&xs[3]=='A')||(rs[3]=='C'&&xs[3]=='B')||(rs[3]=='D'&&xs[3]=='F')||(rs[3]=='F'&&xs[3]=='D')){
				printf("1");
				if((rs[3]=='A'&&xs[3]=='B')||(rs[3]=='B'&&xs[3]=='C')||(rs[3]=='B'&&xs[3]=='A')||(rs[3]=='C'&&xs[3]=='B')||(rs[3]=='D'&&xs[3]=='F')||(rs[3]=='F'&&xs[3]=='D'))printf("1\n");
				else printf("0\n");
			}
			else printf("00\n");
		}
		else printf("000\n");
	}
	else printf("0000\n");
	return 0;
}