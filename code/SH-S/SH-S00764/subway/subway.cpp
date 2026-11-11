#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
const long long inf = 0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q;
long long w[N];
vector<pair<long long,long long>>station[500005];
long long dist[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memset(dist,0x3f,sizeof dist);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>w[i];
	for(int i = 1;i<=n;i++){
		int k;
		cin>>k;
		for(int j = 1;j<=k;j++){
			long long v,w;
			cin>>v>>w;
			station[v].push_back(make_pair(i,w));
		}
		dist[i][i] = 0;
	}
	
	for(int i = 1;i<=m;i++){
		for(int j = 0;j<station[i].size();j++){
			for(int k = 0;k<station[i].size();k++){
				if(j==k) continue;
				long long u = station[i][j].first;
				long long v = station[i][k].first;
				long long w = station[i][j].second + station[i][k].second;
				dist[u][v] = w;
				dist[v][u] = w;
			}
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				if(dist[i][k]!=inf && dist[k][j]!=inf){
					dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
				}
			}
		}
	}
	
	while(q--){
		long long x,y;
		cin>>x>>y;
		long long minx = inf,minl = 0,minr = 0;
		for(int i = 0;i<station[x].size();i++){
			for(int j = 0;j<station[y].size();j++){
				long long d = dist[station[x][i].first][station[y][j].first];
				if(d<minx){
					minx = d;
					minl = station[x][i].second;
					minr = station[y][j].second;
				}
			}
		}
		cout<<minx+w[x]+w[y]+minl+minr<<endl;
	}
	return 0;
}
