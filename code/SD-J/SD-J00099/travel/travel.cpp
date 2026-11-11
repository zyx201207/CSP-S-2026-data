#include<bits/stdc++.h>
using namespace std;
int b1,d1; 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<1;
	}
	else cout<<0;
	if(a==c&&(b[0]==d[0]&&b[1]==d[1]))
	{
		cout<<1;
	}
	else cout<<0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C')
	{
		b1=1;
	}
	else b1=0;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C')
	{
		d1=1;
	}
	else d1=0;
	if((b1==d1)&&(a==c&&(b[0]==d[0]&&b[1]==d[1])))
	{
		cout<<1;
	}
	else cout<<0;	
	if((b1==d1)&&abs(int(b[2]-d[2]))==1&&(a==c&&(b[0]==d[0]&&b[1]==d[1])))
	{
		cout<<1;
	}
	else cout<<0; 
	return 0;
}
