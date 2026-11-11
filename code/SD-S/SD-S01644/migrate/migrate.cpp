#include<bits/stdc++.h>
using namespace std;
const int N = 2e6+10;
int c,t,n,d;
int cd;
int a[N];
int vis[N];
int z[N];
int cnt;
int k;
void dfs(int x,int dis)
{
	if(x+dis>n)
		return;
	vis[x+dis]++;
	for(int i= 1;i<=d/cd;i++)
	{
		
		dfs(x+dis,i);
		
	}
	
}
void dfs1(int x,int dis)
{
	
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		cin >> n >> d;
		for(int i= 1;i<=n;i++)
		{
			cin >> a[i];
		}
		cd = a[n] - a[n-1];
		dfs(1,0);
		for(int i= 1;i<=n;i++)
		{
			if(vis[i] == 2)
				cnt++;
		}
		cout<<cnt<<'\n';
	}
	
	return 0;
}

