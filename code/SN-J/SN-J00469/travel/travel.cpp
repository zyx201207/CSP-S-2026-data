#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c)
	{
		printf("0000");
		return 0;
	}
	if(b[0]!=d[0]||b[1]!=d[1])
	{
		printf("1000");
		return 0;
	}
	if((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(d[2]!='A'&&d[2]!='B'&&d[2]!='C'))
	{
		printf("1100");
		return 0;
	}
	if((b[2]=='D'||b[2]=='F')&&(d[2]!='D'&&b[2]!='F'))
	{
		printf("1100");
		return 0;
	}
	if(b[2]+1==d[2]||d[2]+1==b[2])
		printf("1111");
	else
		printf("1110");
	return 0;
}

