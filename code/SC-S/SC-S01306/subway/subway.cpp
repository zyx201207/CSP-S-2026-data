#include<bits/stdc++.h>
using namespace std;
const int N=1e4+510;
int bh,n,m,shl,q,a[N],vis[N][N],used[N][N],jl;
vector<pair<int,int>>v[N];
void dj(int x)
{
	int len=n+m;
	for(int i=1;i<=len;i++)vis[x][i]=1e9,used[x][i]=0;
	vis[x][x]=0;
	while(1)
	{
		int u=-1,mn=1e9+1;
		for(int i=1;i<=len;i++)
		{
			if(!used[x][i]&&vis[x][i]<mn)
			{
				mn=vis[x][i];
				u=i;
			}
		}
		if(u==-1)break;
		used[x][u]=1;
		for(auto i:v[u])vis[x][i.first]=min(vis[x][i.first],i.second+mn);
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>bh>>m>>n>>shl>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1,o;i<=m;i++)
	{
		cin>>o;
		for(int j=1,x,y;j<=o;j++)
		{
			cin>>x>>y;
			jl=y;
			v[n+i].push_back({x,y});
			v[x].push_back({n+i,y});
		}
	}
	for(int i=1;i<=n;i++)
	{
		dj(i);
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<vis[x][y]+a[x]+a[y]<<'\n';
	}
	return 0;
}
/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2


*/