#include<bits/stdc++.h>
#define int long long
#define writen ios::sync_with_stdio(false);
#define by cin.tie(0);
#define Sxi cout.tie(0)
using namespace std;
const int N=1e6+10;
int n,m,t[501][5000],z[N],c,d,q,a[1000][1000],k[N],w[N];
bool vis[N];
vector<int> dis[N];
vector<int> e[N];//边连接两点 w[u][v]=t[i][i]+t[i][j]
void dijstra(int s)
{
	
	memset(vis,false,sizeof(vis));
	priority_queue<pair<int,int> >q;//dis id
	q.push({0,s});
	for(int i=1;i<=m+10;i++) dis[s].push_back(INT_MAX);//memset
	dis[s][s]=0;
	while(q.size())
	{
		pair<int,int> nd=q.top();
		q.pop();
		if(vis[nd.second]) continue;
		vis[nd.second]=true;
		int udis=nd.first,u=nd.second,ui=-1;
		udis=-udis;
		for(int i=0;i<e[u].size();i++)
		{
			for(int j=1;j<=k[e[u][i]];j++)
			{
				if(a[e[u][i]][j]==u)
				{
					ui=j;
					break;
				}
			}
			for(int j=1;j<=k[e[u][i]];j++)
			{
				int v=a[e[u][i]][j];
				if(u==v) continue;
				if(udis+t[e[u][i]][ui]+t[e[u][i]][j]<dis[s][v])
				{
					dis[s][v]=dis[s][u]+t[e[u][i]][ui]+t[e[u][i]][j];
					q.push({-dis[s][v],v});
					//cout<<u<<"->"<<v<<":"<<t[e[u][i]][ui]<<" "<<t[e[u][i]][j]<<endl;
					//cout<<"s:"<<s<<" dis[v]="<<dis[v]<<endl;
				}
			}
			
		}
	}
}
signed main()
{
	writen by Sxi;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>z[i];
	}
	memset(t,0x3f,sizeof(t));
	for(int i=1;i<=n;i++)
	{
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
		{
			cin>>a[i][j]>>t[i][j];
			e[a[i][j]].push_back(i);
		}
	}
	while(q--)
	{
		int s,e;
		cin>>s>>e;
		if(dis[s].size())
		{
			cout<<dis[s][e]+z[s]+z[e]<<"\n";
			//cout<<1<<" "<<mp[s][e]<<endl;
			continue;
		}
		dijstra(s);
		cout<<dis[s][e]+z[s]+z[e]<<"\n";
		//cout<<2<<" "<<dis[e]<<endl;
	}
	return (0^0);
}

