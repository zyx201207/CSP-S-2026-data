#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=0x3f3f3f3f3f3f;
int c,n,m,d,q,w[500005],ans=0,dis[200005],a[200005],t[200005];//d为站厅 1 2为站台 
int trans(int x,int y)//x号线的y站 
{
	return x*m+y;
}
vector<pair<int,int> > g[100005];//v,w
void add(int u,int v,int w)
{
	g[u].push_back({v,w});
 } 
queue<int> qr;
signed main()
{
	ios::sync_with_stdio();
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//m=5;
	//cout<<trans(2,3);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int len;
		cin>>len;
		for(int j=1;j<=len;j++)
		{
			cin>>a[j]>>t[j];
			add(m+i,a[j],t[j]);
			add(a[j],m+i,t[j]);
		}
//		for(int j=1;j<len;j++)
//		{
//			int u=trans(i,a[j]),v=trans(i,a[j+1]);
//			add(u,v,0);
//			add(v,u,0);
//		}
	}
//	for(int i=1;i<=m+n;i++)
//	{
//		for(int j=0;j<g[i].size();j++)
//		{
//			int v=g[i][j].first,w=g[i][j].second;
//			cout<<i<<"->"<<v<<"的边权为"<<w<<endl;
//		}
//	}
	while(q--)
	{
		int st,ed;
		cin>>st>>ed;
		memset(dis,0x3f3f3f3f3f,sizeof(dis));
		while(!qr.empty()) qr.pop();
		dis[st]=0;
		qr.push(st);
		while(!qr.empty()) 
		{
			int u=qr.front();
			//cout<<u<<endl;
			qr.pop();
			for(int i=0;i<g[u].size();i++)
			{
				int v=g[u][i].first,w=g[u][i].second;
				if(dis[u]+w<dis[v])
				{
					dis[v]=dis[u]+w;
					qr.push(v);
				}
			}
		}
//		for(int i=1;i<=(n+1)*m;i++) cout<<st<<"->"<<i<<"的距离"<<dis[i]<<endl;
		//cout<<endl;
		cout<<w[st]+w[ed]+dis[ed]<<endl;
	}
	return 0;
 } 
