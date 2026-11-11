#include<bits/stdc++.h>
using namespace std;
int c1,a1,c2,a2;
char b1,b2,s[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&c1,&a1,&b1,&c2,&a2,&b2);
	for(int i=0;i<4;i++)s[i]='0';
	if(c1==c2){
		s[0]='1';
		if(a1==a2){
			s[1]='1';
			if((b1<='C'&&b2<='C')||(b1>'C'&&b2>'C')){
				s[2]='1';
				if(abs(b1-b2)==1||(b1=='F'&&b2=='D')||(b1=='D'&&b2=='F'))s[3]='1';
			}	
		}
	}
	printf("%s",s);
	return 0;
}
