#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],ans=-1,tmp=1;
void dfs(int step,int id,int cnt)
{
	if(id==n+1)
	{
		if(step==m)
		{
			ans=max(ans,cnt);
		}
		return; 
	}
	
	dfs(step+1,id+1,cnt&a[id]);
	dfs(step,id+1,cnt);
	
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int mx=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
	}
	if(m==1)
	{
		cout<<mx;
		return 0;
	}
	if(m==n)
	{
		int tmp=a[1];
		for(int i=2;i<=n;i++)
		{
			tmp&=a[i];
		} 
		cout<<tmp;
		return 0; 
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=20)
	{
		dfs(0,1,(2<<20)-1);
		cout<<ans;
		return 0;
	} 
	int flag=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=i-1)
		{
			flag=1;
		}
	}
	sort(a+1,a+n+1,greater<int>());
	ans=a[1];
	for(int i=2;i<=m;i++)
	{
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

