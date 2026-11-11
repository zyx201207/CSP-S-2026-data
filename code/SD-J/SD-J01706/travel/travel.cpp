#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
char b1,b2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d %d%c",&c1,&s1,&b1);
	scanf("%d %d%c",&c2,&s2,&b2);
	if(c1==c2){
		printf("1");
		if(s1==s2){
			printf("1");
			if((b1<='C')==(b2<='C')){
				printf("1");
				if(abs(int(b2)-int(b1))==1)printf("1");
				else printf("0");
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	return 0;
}

