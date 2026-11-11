#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long g,h;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		printf("1");
		if(b[0]==d[0]&&b[1]==d[1]){
			printf("1");
			if(((b[2]<='C')&&(d[2]<='C'))||((b[2]>'C')&&(d[2]>'C'))) printf("1");
			else printf("0");
		}
		else printf("00");
		g=(b[0]-'0')*10+b[1]-'0';
		h=(d[0]-'0')*10+d[1]-'0';
		if(((abs(g-h)==1)&&(b[2]==d[2]))||((abs(b[2]-d[2])==1)&&(g-h==0)&&(min(b[2],d[2])!='C')&&(max(b[2],d[2])!='D'))) printf("1");
		else printf("0");
		
	}
	else printf("0000");
	return 0;
}