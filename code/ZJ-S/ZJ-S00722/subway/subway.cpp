#include<bits/stdc++.h>
using namespace std;
#define int long long
#define PI pair<int,int>
const int N=5e5+10;
int c,n,m,d,q,v[N],k[1010],ans;
vector<int>g[N];
vector<PI>a[N];
bool vis[1010][1010];
void dfs(int x,int z,int y,int sum)
{
	if(x==y)
	{
		ans=min(ans,v[y]+sum);
		return ;
	}
	for(auto k1:g[x])
	{
		for(auto v1:a[k1])
		{
			int p=v1.first,t=v1.second;
			if(p==x&&k1==z||vis[p][k1]) continue;
			if(k1!=z&&p!=x&&z!=0) continue;
			if(z==0&&p!=x) continue;
			vis[p][k1]=1;
			dfs(p,k1,y,sum+t);
			vis[p][k1]=0;
		}
	}
	return ;
}
void solve_1()
{
	for(int i=1;i<=q;i++)
	{
		ans=1e18;
		int x,y;
		cin>>x>>y;
		dfs(x,0,y,v[x]);
		cout<<ans<<'\n';
	}
	return ;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>v[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			int x,y;
			cin>>x>>y;
			a[i].push_back({x,y});
			g[x].push_back(i);
		}
	}
	solve_1();
	return 0;
}
