#include<bits/stdc++.h>//T2
#define int long long
using namespace std;
const int N=5e5+5;
int c,n,m,d,q;
int w[N],k[505],ans[505][10005];
map<int,int> lk[505];
vector<int> a[505],t[505];
vector<pair<int,int> >b[N];
int bfs(int x,int y)
{
	memset(ans,0x3f3f3f3f,sizeof ans);
	priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > >,greater<pair<int,pair<int,int> > > > d;
	for(int i=1;i<(int)b[x].size();i++)
	{
		d.push({t[b[x][i].first][b[x][i].second],{x,i}});
		ans[i][x]=t[b[x][i].first][b[x][i].second];
	}
	while(!d.empty())
	{
		int u=d.top().second.first,bw=d.top().first,xian=d.top().second.second;
		d.pop();
		if(u==y) return w[x]+w[y]+bw;
		for(int i=1;i<(int)b[u].size();i++)
		{
			if(b[u][i].first==xian) continue;
			int c[5]={bw+t[xian][lk[xian][u]]+t[b[u][i].first][b[u][i].second],u,b[u][i].first};
			if(ans[c[2]][c[1]]<=c[0]) continue;
			d.push({c[0],{c[1],c[2]}});
			ans[c[2]][c[1]]=c[0];
		}
		for(int i=1;i<=k[xian];i++)
		{
			int v=a[xian][i],ww=bw;
			if(v==y) ww+=t[xian][i];
			if(ans[xian][v]<=ww) continue;
			d.push({ww,{v,xian}});
			ans[xian][v]=ww;
		}
	}
	return 0;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++) b[i].push_back({0,0});
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&k[i]);
		a[i].push_back(0);
		t[i].push_back(0);
		for(int j=1;j<=k[i];j++)
		{
			int ca,ct;
			scanf("%lld%lld",&ca,&ct);
			a[i].push_back(ca);
			b[ca].push_back({i,j});//第i条第j个
			lk[i][ca]=j;
			t[i].push_back(ct);
		}
	}
	while(q--)
	{
		int x,y;
		scanf("%lld%lld",&x,&y);
		int ans=bfs(x,y);
		printf("%lld\n",ans);
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
