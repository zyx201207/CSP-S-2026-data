#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005],n,m;
long long f,d,ans=-1;
long long dfs(int t,int now,int step)
{ 
	if(s[t]*(step-1)>now||t>n)
	{
		return step-1;
	}
	if(s[t]*(step-1)==now)
	{
		while((t<n)&&s[t+1]==0)step++,t++;
		return step;
	}
	if(s[t]*(step-1)<now)
	{
		return dfs(t+1,(now-s[t]*(step-1)),step+1);
	}
}
int main()
{
	freopen("crystal.in" , "r" , stdin);
	freopen("crystal.out" , "w" , stdout);
	cin>>n>>m;
	cin>>a[1];
	f=a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];
		if(f!=a[i])f=100000000001;
	}
	if(f!=100000000001)
	{
		cout<<n;
		return 0;	
	}
	sort(a+1,a+n+1);
	a[0]=0;
	s[1]=0,s[2]=a[2]-a[1],d=s[2];
	for(int i=3;i<=n;i++)
	{
		s[i]=a[i]-a[i-1];
		if(d!=s[i])d=200000000001;
	}
	if(d!=200000000001)
	{
		for(int i=n;i>=1;i--)
		{
			if((m*2/d)>=i*(i+1))
			{
				cout<<i+1;
				return 0;
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		ans=max(ans,dfs(i,m,1));
	}
	cout<<ans;
	return 0;
} 
