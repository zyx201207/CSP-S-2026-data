#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=5e5+5,N=5e2+5,Q=1e5+5;
int c,n,m,d,q,w[M],k[N],a[N][M],t[N][M],x,y,ans;
vector<vector<pair<int,int>>> station(m);
bool f[N][M];
void dfs(int end,int now,int nowline,int s)
{
	if(now==end)
	{
		ans=min(ans,s);
		return;
	}
	for(int i=1;i<=k[nowline];i++)
	{
		if(a[nowline][i]!=now && !f[nowline][a[nowline][i]])
		{
			f[nowline][a[nowline][i]]=true;
			dfs(end,a[nowline][i],nowline,s);
			f[nowline][a[nowline][i]]=false;
		}
	}
	for(auto it:station[now])
	{
		if(nowline!=it.first && !f[it.first][a[nowline][now]])
		{
			f[nowline][a[nowline][now]]=true;
			dfs(end,now,it.first,s+t[nowline][now]+t[it.first][now]);
			f[nowline][a[nowline][now]]=false;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			station[a[i][j]].push_back({i,t[i][j]});
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		ans=INT_MAX;
		dfs(y,x,station[x][0].first,w[x]+w[y]);
		cout<<ans; 
	}
	return 0;
}
