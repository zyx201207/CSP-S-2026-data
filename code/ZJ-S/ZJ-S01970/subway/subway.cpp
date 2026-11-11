#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],u,v,k,dist[505][505],s[500005][25],r,t,x[100005],y[100005],ts[500005][25],ans,jj,ll;
struct Edge{
	long long y,v;
	Edge(long long _y,long long _v){y=_y,v=_v;}
};
vector<Edge> g[505];
void dijkstra(int s){
	set<pair<long long,int>> qs;
	qs.clear();
	dist[s][s]=0;
	for(int i=1;i<=n;i++)
		qs.insert({dist[s][i],i});
	while(!qs.empty()){
		int x=qs.begin()->second;
		qs.erase(qs.begin());
		if(dist[s][x]>(1ll<<50))
			break;
		for(auto i:g[x]){
			if(dist[s][x]+i.v<dist[s][i.y]){
				qs.erase({dist[s][i.y],i.y});
				dist[s][i.y]=dist[s][x]+i.v;
				qs.insert({dist[s][i.y],i.y});
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>r>>t;
			s[r][++s[r][0]]=i;
			ts[r][s[r][0]]=t;
		}
	}
	for(int i=1;i<=q;i++)
		cin>>x[i]>>y[i];
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=m;i++){
		for(int j=1;j<=s[i][0];j++){
			for(int l=j+1;l<=s[i][0];l++){
				jj=s[i][j],ll=s[i][l];
				dist[jj][ll]=min(dist[jj][ll],ts[i][j]+ts[i][l]);
				dist[ll][jj]=dist[jj][ll];
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(dist[i][j]<(1ll<<50)){
				g[i].push_back(Edge(j,dist[i][j]));
				g[j].push_back(Edge(i,dist[j][i]));
			}
		}
	}
	memset(dist,0x3f,sizeof(dist));
	for(int i=1;i<=n;i++)
		dijkstra(i);
	for(int i=1;i<=q;i++){
		ans=1e16;
		for(int dep=1;dep<=s[x[i]][0];dep++){
			for(int arr=1;arr<=s[y[i]][0];arr++){
				ans=min(ans,dist[s[x[i]][dep]][s[y[i]][arr]]+ts[x[i]][dep]+ts[y[i]][arr]);
			}
		}
		cout<<ans+w[x[i]]+w[y[i]]<<'\n';
	}
	return 0;
} 
