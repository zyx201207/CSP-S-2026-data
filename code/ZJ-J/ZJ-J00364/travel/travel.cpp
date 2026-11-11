#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int c1,c2,c3,c4;
	if(a==c)c1=1;
	else c1=0;
	if(b[0]==d[0]&&b[1]==d[1]&&c1)c2=1;
	else c2=0;
	if((((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C'))||
	((b[2]=='D'||b[2]=='F'))&&(d[2]=='D'||d[2]=='F'))&&c2&&c1)c3=1;
	else c3=0;
	if(c3&&c2&&c1&&(b[2]==d[2]+1||d[2]==b[2]+1))c4=1;
	else c4=0;
	printf("%d%d%d%d\n",c1,c2,c3,c4);
	return 0;
}
