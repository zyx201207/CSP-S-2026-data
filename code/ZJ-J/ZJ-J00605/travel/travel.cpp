#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char p1,p2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&c1,&s1,&p1,&c2,&s2,&p2);
	if(c1!=c2)puts("0000");
	else{
		putchar('1');
		if(s1!=s2)puts("000");
		else{
			putchar('1');
			if(min(p1,p2)<='C'&&max(p1,p2)>='D')puts("00");
			else{
				putchar('1');
				if(abs(p1-p2)>1)putchar('0');
				else putchar('1');
			}
		}	
	}
	return 0;
}