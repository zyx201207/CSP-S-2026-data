#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=501,M=5e5+10,INF=1e18+10;
struct R
{
	int v,to;
};
int v[200001][N],yuan[M],stk;
vector<R> r[M];
int w[M];
int dis[N][N];
int q[M][2],b[M],ls[M];
int n,m;
void floyd(){for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0); 
	cin.tie(0);
	int c,d,Q;
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	int len,pos,t;
	for(int i=1;i<=n;i++)
	{
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			cin>>pos>>t;
			R x;
			x.to=i,x.v=t;
			r[pos].push_back(x);
		}
	}
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=m;i++)
	{
		int x=r[i].size();
		for(int j=0;j<x;j++)
		{
			for(int k=0;k<x;k++)
			{
				if(k==j) continue;
				int u=r[i][j].to,_v=r[i][k].to;
				dis[u][_v]=min(dis[u][_v],r[i][j].v+r[i][k].v);
			}
		}
	}
	for(int i=1;i<=n;i++) dis[i][i]=0;
	floyd();
	for(int i=1;i<=Q;i++)
	{
		cin>>q[i][0]>>q[i][1];
		b[q[i][0]]=b[q[i][1]]=1;
	}
	int st=clock();
	for(int i=1;i<=m;i++)
	{
		if(b[i])
		{
			int x=r[i].size();
			stk++;
			for(int k=1;k<=n;k++) v[stk][k]=INF;
			for(int j=0;j<x;j++)
			{
				for(int k=1;k<=n;k++)
				{
					v[stk][k]=min(v[stk][k],r[i][j].v+dis[r[i][j].to][k]);
				}
			}
			yuan[i]=stk;
		}
	}
	int ed=clock();
//	cout<<ed-st;
	for(int i=1;i<=Q;i++)
	{
		int res=INF;
		for(int j=1;j<=n;j++)
		{
			int u=yuan[q[i][0]],_v=yuan[q[i][1]];
			res=min(res,v[u][j]+v[_v][j]);
		}
		cout<<res+w[q[i][0]]+w[q[i][1]]<<'\n'; 
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

*/