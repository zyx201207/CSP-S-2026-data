#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=2e6+15;
int c,t;
int n,d;
int a[N];
int lsans;
void dfs(int now,int to,int k,int nowk)
{
	if(now==to && nowk==k)
	{
		lsans++;
	}
	for(int i=now+1;i<=n;i++)
	{
		if(a[i]-a[now]<=d)
		{
			dfs(i,to,k,nowk+1);
		}
	}
	return;
}
bool check(int a,int b)
{
	dfs(a,b,(b-a+d-1)/d,0);
	if(lsans==2)
	{
		lsans=0;
		return true;
	}
	else
	{
		lsans=0;
		return false;
	}
}
void solve()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];		
	}
	int ans=0;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(check(i,j))
			{
				ans++;
			}
		}		
	}		
	cout<<ans<<"\n";
	return;
}
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		solve();	
	}	
	return 0;
}