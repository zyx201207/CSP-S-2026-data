#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],mx=0,sum=0,cnt=0;
bool vis[N];
void dfs(int x)
{
	if(cnt==m)
	{
		mx=max(mx,sum);
		cnt=0;
		return;
	}
	if(cnt==0)
	{
		sum=a[x];
	}
	else sum=(sum&a[x]);
	cnt++;
	for(int j=1;j<=n;j++)
	{
		if(!vis[j])
		{
			vis[j]=true;
			dfs(j);
			vis[j]=false;
		}
	}
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	sum=a[1];
	for(int i=2;i<=n;i++)
	{
		sum=(sum&a[i]);
	}
	if(m==1)
	{
		cout<<mx<<"\n";
		return 0;
	}
	if(m==n)
	{
		cout<<sum<<"\n";
		return 0;
	}
	if(m==2)
	{
		mx=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue;
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx<<"\n";
		return 0;
	}
	mx=0,sum=0;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		vis[i]=true;
		dfs(i);
		vis[i]=false;
		ans=max(ans,mx);
	}
	cout<<ans<<"\n";
	return 0;
}
