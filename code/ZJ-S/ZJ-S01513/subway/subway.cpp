#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N=2e3+7;
struct
{
	int zd;
	ll w;
	vector<int>x;
}g[507][N];
ll Sum=1e18;
ll c,n,m,d,q,se[N],mk=-1,ans;
bool vis[N];
void dfs(ll d,ll sum,ll e,ll sx)
{
	queue<pair<ll,ll>>q;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=mk;j++)
		{
			if(g[i][j].zd==0)break;
			if(g[i][j].zd==d)
			{
				ll I=i,J=j;
				q.push({I,J});
			}
		}
	}
	while(!q.empty())
	{
		ll X=q.front().first;
		ll Y=q.front().second;
		if(X==sx)sum+=g[X][Y].w;
		if(d==e)
		{
			Sum=min(sum,Sum);
			return ;
		}
		q.pop();
		for(ll nx:g[X][Y].x)
		{
			if(vis[nx]==1)continue;
			vis[nx]=1;
			dfs(nx,sum+g[X][Y].w,e,X);
			vis[nx]=0;
		}
	}
}
/*
0 1 5 20 2
4 1 9 2 5
3 
1 5 
2 7 
4 6
3 
2 3 
3 4 
5 7
1 2
*/
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>se[i];
	for(int i=1;i<=n;i++)
	{
		ll k;
		cin>>k;
		mk=max(mk,k);
		for(int j=1;j<=k;j++)
		{
			cin>>g[i][j].zd>>g[i][j].w;
			for(int ij=j;ij>=1;ij--)
			{
				g[i][j].x[g[i][j].zd].push_back(g[i][ij].zd);
				g[i][ij].x[g[i][ij].zd].push_back(g[i][j].zd);
			}
		}
	}
	while(q--)
	{
		int mx,y;
		cin>>mx>>y;
		Sum=1e18;
		vis[mx]=1;
		dfs(mx,0,y,0);
		ans+=(Sum+se[mx][y]);
		cout<<ans<<"\n";
	}
}
