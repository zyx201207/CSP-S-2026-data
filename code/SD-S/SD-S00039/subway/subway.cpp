#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=509,M=5e5+9;
const ll INF=2e18;
int c,n,m,d,q,w[M],K,x,y;
ll dist[N][N],ans;
vector<pair<int,int> > t[M];
void cmin(ll &u,ll v){u=min(u,v);}
void fyd()
{
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)cmin(dist[i][j],dist[i][k]+dist[k][j]);
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>K;
		for(int j=1;j<=K;j++){
			cin>>x>>y;
			t[x].push_back({i,y});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)dist[i][j]=INF;
		dist[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<t[i].size();j++){
			for(int k=j+1;k<t[i].size();k++){
				int u=t[i][j].first,v=t[i][k].first;
				ll W=t[i][j].second+t[i][k].second;
				dist[u][v]=dist[v][u]=min(dist[u][v],W);
			}
		}
	}
	fyd();
	while(q--){
		cin>>x>>y;
		ans=INF;
		for(auto i:t[x]){
			for(auto j:t[y]){
				cmin(ans,dist[i.first][j.first]+i.second+j.second);
			}
		}
		ans+=w[x]+w[y];
		cout<<ans<<"\n";
	}
	return 0;
}
