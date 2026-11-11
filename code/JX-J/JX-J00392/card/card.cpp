#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500009],o,p[300009],c=1,t,mm[300009];
bool ma[300009];
void f(int u,int c)
{
	t=0;
	int i=1;
	while(i<=c)
	{
		if(p[i]==u) 
		{
			t++;
			c=i-1;
		}
		else if(p[i]!=u and t==1) 
		{
			ma[p[i]]=0;
			p[i]=0;
		}
	}
}
int main()
{
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
cin>>n>>m;
for(int i=1;i<=n;i++) cin>>a[i];
for(int i=1;i<=m;i++)
{
	o=i;
	c=1;
	while(o<=n)
	{
		p[c]=a[o];
		if(ma[a[o]]==1) f(a[o],c);
		c++;
		o++;
	}
	c=1;
	while(p[c]!=0) mm[p[c]]++;
}
for(int i=1;i<=m;i++) cout<<mm[i]<<" ";
return 0;
}
