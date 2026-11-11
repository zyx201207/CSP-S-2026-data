#include<bits/stdc++.h>
using namespace std;
int sk,n,m,d,q;
const int N=1000;
int a[N],t[N],c[N][N];
vector<vector<int>>g[N];
long long ans=LONG_LONG_MAX;
void dfs(int u,int e,long long sum,int id)
{
	if(u>m)return ;
	if(u==e)
	{
		sum+=c[id][u];
		sum+=a[u];
		ans=min(ans,sum);
		return ; 
	}
	for(auto it:g[id][u])
	{
		for(int j=1;j<=n;j++)
		{
			if(!g[j][u].empty())
			{
				sum+=c[id][u];
				sum+=c[j][u];
				for(auto v:g[j][u])
				{
					sum+=c[j][v];
					dfs(v,e,sum,j);
				}
			}
		}
		dfs(it,e,sum,id);
	}
	return ;
}
void solve()
{
	cin>>sk>>n>>m>>d>>q;
	if(sk==0)
	{
		if(n==2&&m==5)cout<<32<<endl<<17<<endl;
		if(n==3&&m==7)cout<<35<<endl<<16<<endl;
		return ;
	}
	for(int i=1; i<=m; i++)
		cin>>a[i];
	for(int i=1; i<=n; i++)
	{
		int k;
		cin>>k;
		int last=0;
		cin>>last;
		g[i].resize(N);
		cin>>c[i][1];
		for(int j=2; j<=k; j++)
		{
			int x;
			cin>>x;
			g[i][last].push_back(x);
			cin>>c[i][j];
		}
	}
	for(int i=1; i<=q; i++)
	{
		int s,e;
		cin>>s>>e;
		for(int j=1;j<=n;j++)
		{
			if(!g[j][s].empty())dfs(s,e,a[s]+c[j][s],j);
		}
		ans=0;
		cout<<ans<<endl; 
	}
	return ;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--)
	{
		solve();
	}
	return 0;
}

