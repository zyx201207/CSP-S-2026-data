#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,qq;
long long w[500010];
map<int,long long> mp[500010];
vector<int> e[510];
vector<int> e1[500010];
long long dis[510][510];
bool vis[510][510];
struct R{
	long long xl,zd;
	bool operator < (const R &x) const{
		return zd>x.zd;
	}
};
void dij(int x,int sh){
	priority_queue<R> q;
	q.push({x,0});
	while(!q.empty()){
		int u=q.top().xl;
		q.pop();
		if(vis[sh][u]) continue;
		vis[sh][u]=1;
		for(auto v:e[u]){
			for(auto z:e1[v]){
				if(vis[sh][z]) continue;
				if(dis[sh][u]+mp[v][u]+mp[v][z]<dis[sh][z]){
					dis[sh][z]=dis[sh][u]+mp[v][u]+mp[v][z];
					q.push({z,dis[sh][z]});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	memset(dis,0x3f,sizeof dis);
	cin >> c >> n >> m >> d >> qq;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		for(int j=1;j<=k;j++){
			long long a,t;
			cin >> a >> t;
			e[i].push_back(a);
			e1[a].push_back(i);
			mp[a][i]=t;
		}
	}
	for(int i=1;i<=n;i++){
		dis[i][i]=0;
		dij(i,i);
	}
	while(qq--){
		int l,r;
		cin >> l >> r;
		long long ans=1e18;
		for(auto v:e1[l]){
			for(auto z:e1[r]) ans=min(ans,dis[v][z]+mp[l][v]+mp[r][z]);
		}
		cout << ans+w[l]+w[r] << '\n';
	}
	return 0;
}
