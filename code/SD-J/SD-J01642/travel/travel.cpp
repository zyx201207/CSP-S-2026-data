#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
struct st{
	long long c;
	char s;
}a[7][20];
long long n,j,i,m,xj,yj,d,r,f=0;
string x,y;
char xx,yy;
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>x>>m>>y;
	for(i=0;i<x.size()-1;i++)
	{
		d=d*10+(x[i]-'0');
	}
	for(i=0;i<y.size()-1;i++)
	{
		r=r*10+(y[i]-'0');
	}
	xx=x[x.size()-1];
	yy=y[y.size()-1];
	if(xx=='A') xj=1;
	if(xx=='B') xj=2;
	if(xx=='C') xj=3;
	if(xx=='D') xj=5;
	if(xx=='F') xj=6;
	if(yy=='A') yj=1;
	if(yy=='B') yj=2;
	if(yy=='C') yj=3;
	if(yy=='D') yj=5;
	if(yy=='F') yj=6;
	if(n==m)
	{
		cout<<1;
		if(d==r&&f==0)cout<<1;
		else
		{
			cout<<0;
			f=1;
		}
		if(((xj>4&&yj>4)||(xj<4&&yj<4))&&f==0) cout<<1;
		else
		{
			cout<<0;
			f=1;
		}
		if(abs(xj-yj)==1&&f==0) cout<<1;
		else
		{
			cout<<0;
			f=1;
		}
	}
	else cout<<"0000";
	return 0;
} 
