#include<bits/stdc++.h>
#define int long long
using namespace std; 

const int N=2e5+5;
const int inf=2e9+8;

int ans=0;
int c,t,n,k;
int u[N],v[N];


int st;
int sum[N];
bool vis[N];
vector<int>mp[N];

void dfs(int a,int p,int sum)
{
	if(a==p)
	{
		ans=min(ans,sum);
		sum=ans;
		return ;
	}
	vis[a]=1;
	for(int i=0;i<mp[a].size();i++)
	{
		if(!vis[mp[a][i]])
		{
			dfs(mp[a][i],p,sum+1);	
			vis[mp[a][i]]=0;
		}
	}
	return ;
}

void solve()
{
	ans=0;
	for(int i=1;i<=n;i++)
	{
		sum[i]=inf;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dfs(i,j,0);
			sum[i]=min(ans,sum[i]);
		}
	}
	sort(sum+1,sum+n+1);
	int as=sum[1]==0?1:sum[1];
	cout<<as<<'\n';
}

signed main()
{
	freopen("hub.in","r",stdin);	
	freopen("hun.out","w",stdout);	
	cin>>c>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n>>k;
		for(int j=1;j<=n-1;j++)
		{
			cin>>u[j]>>v[j];
			mp[v[j]].push_back(u[j]);	
			mp[u[j]].push_back(v[j]);	
		}
		solve();
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5

*/
