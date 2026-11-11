#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5+5;

int n,m;
int a[maxn];
int mx;

void dfs(int x,int ans,int i)
{
	if(x==m)
	{
		mx=max(mx,ans);
		return ;
	}
	for(int j=i+1;j<=n;j++)
	{
		if(j==i) continue;
		dfs(x+1,ans&a[j],j);
	}
}

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dfs(1,a[i],i);
	}
	cout<<mx;
	
	return 0;
}

