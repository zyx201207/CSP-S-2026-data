#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+1,M=501;
const ll INF=1e17;
int n,m,q;
ll dist[M][M],w[N];
void fil()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
}
void adde(int x,int y,ll w){dist[x][y]=dist[y][x]=min(dist[x][y],w);}
vector<pair<int,int>>vec[N];
int main()
{
	fil();
	ios::sync_with_stdio(false);
	int rb;
	cin>>rb>>m>>n>>rb>>q;
	for(int i=1;i<=n;i++)cin>>w[i];
	for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)if(i!=j)dist[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int s,x;cin>>s;
		for(int j=1;j<=s;j++){int x,y;cin>>x>>y;vec[x].emplace_back(i,y);}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		for(int k=j+1;k<vec[i].size();k++)adde(vec[i][j].first,vec[i][k].first,vec[i][j].second+vec[i][k].second);
	}
	for(int k=1;k<=m;k++)
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
	while(q--)
	{
		int s,t;
		ll min_d=INF;
		cin>>s>>t;
		for(int j=0;j<vec[s].size();j++)
		for(int k=0;k<vec[t].size();k++)
		{
			int S=vec[s][j].first,Sc=vec[s][j].second;
			int T=vec[t][k].first,Tc=vec[t][k].second;
			min_d=min(min_d,dist[S][T]+Sc+Tc);
		}
		cout<<w[s]+w[t]+min_d<<'\n';
	}
}
