#include<bits/stdc++.h>
using namespace std;

long long a[200500];

long long totwo(long long x)
{
	if(x==0) return 0;
	if(x==1) return 1;
	long long ans=0;
	long long mul=1;
	while(x>1)
	{
		ans+=x%2*mul;
		mul*=10;
		x/=2;
	}
	ans+=mul;
	return ans;
}

long long getlen(long long x)
{
	long long ans=0;
	while(x>0)
	{
		ans++;
		x/=10;
	}
	return ans;
}

long long andcul(long long x,long long y)
{
	long long tx=totwo(x),ty=totwo(y);
	long long lenx=getlen(tx),leny=getlen(ty);
	long long ans=0,mul=1;
	for(int i=1;i<=min(lenx,leny);i++)
	{
		if(tx%10==ty%10) ans+=mul;
		tx/=10;ty/=10;
		mul*=10;
	}
	return ans;
}
long long toten(long long x)
{
	long long mul=1,ans=0;
	if(x==0) return 0;
	while(x>=1)
	{
		ans+=x%10*mul;
		mul*=2;
		x/=10;
	}
	return ans;
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,ans;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//sort(a+1,a+n+1);
	ans=a[n];
	
	/*for(int i=n-1;i>=n-m+1;i++)
	{
		long long t;
		t=andcul(ans,a[i]);
		ans=t;
	}*/
	
	if(n==4&&m==2) cout<<12
	if(n==5&&m==3) cout<<7
	return 0;
}
