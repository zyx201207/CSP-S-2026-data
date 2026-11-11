#include <bits/stdc++.h>
using namespace std;
int a[111111];
dfs(long long x,long long y)
{
	
	y=11111;
	for(long long i=2;i<=x;i++)
	{
		
		long long p=i;
		if(a[p]-a[p-1]>0)
		{
			if(a[p]-a[p-1]<y and a[p]-a[p-1]>=0) y=p-1;
		}
		if(a[p]==a[p-1]) y=p-1;			
	}
	return y;
}
int main()
{
	freopen("crystal.in","r",stdin)
	freopen("crystal.out","w",stdout)
	long long n,m,t,cnt=0;cin>>n>>m;
	t=n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	long long _=11111;
	for(long long i=1;;)
	{
		dfs(n,_);
		
		a[_]+=1;t-=1;
		
		if(t<=0)
		{
			break;
		}
		if(a[_+1]-a[_]<=0)
		{
			cnt+=1;
			a[_+1]+=i*2000;
			
			
		} 
		
	}
	
	cout<<cnt;							
	return 0;
} 
