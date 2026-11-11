#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=0;
int a,b,sum=0,c[10];
char x[5],y[5];
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a;
	for(int i=1;i<=4;i++) c[i]=1;
	for(int i=0;i<3;i++) cin>>x[i];
	cin>>b;
	if(a!=b)
	{
		c[1]=0;
		sum=1;
	}
	else c[1]=1;
	for(int i=0;i<3;i++) cin>>y[i];
	for(int i=0;i<2;i++)
	{
		if(x[i]!=y[i]||c[1]==0) c[2]=0;
	}
	if(x[2]=='D'&&y[2]!='F')
	{
		c[3]=0;
		c[4]=0;
	}
	if(x[2]=='F'&&y[2]!='D')
	{
		c[3]=0;
		c[4]=0;
	}
	if(x[2]=='A')
	{
		if(y[2]!='B'||c[1]==0||c[2]==0) c[4]=0;
		if((y[2]!='C'&&y[2]!='B')||c[1]==0||c[2]==0) c[3]=0;
	}
	if(x[2]=='B')
	{
		if((y[2]!='A'&&y[2]!='C')||c[1]==0||c[2]==0)
		{
			c[3]=0;
			c[4]=0;
		}
	}
	if(x[2]=='C')
	{
		if(y[2]!='B'||c[1]==0||c[2]==0) c[4]=0;
		if((y[2]!='A'&&y[2]!='B')||c[1]==0||c[2]==0) c[3]=0;
	}
	for(int i=1;i<=4;i++) cout<<c[i]; 
	return 0;
}
