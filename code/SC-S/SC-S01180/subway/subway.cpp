#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+7;
long long c,n,m,d,q,w[N],k[N],mp[507][507],dist[507][507];
vector<pair<long long,long long>> sta[N];
vector<long long> s[N];

void dfs(long long x){
	queue<long long> q;
	dist[x][x]=0;
	q.push(x);
	while(!q.empty()){
		long long u=q.front();
		q.pop();
		for(long long v:s[u]){
			if(dist[v][x]>dist[u][x]+mp[u][v]){
				dist[v][x]=dist[u][x]+mp[u][v];
				q.push(v);
			}
		}
	}
}

void solve(){
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=n;j++){
			mp[i][j]=9e18;
			dist[i][j]=9e18;
		}
	}
	for(long long i=1;i<=m;i++) cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(long long j=1,in1,in2;j<=k[i];j++){
			cin>>in1>>in2;
			sta[in1].push_back({i,in2});
		}
	}
	for(long long i=1;i<=m;i++){
		for(long long a=0;a<sta[i].size();a++){
			for(long long b=a+1;b<sta[i].size();b++){
				mp[sta[i][a].first][sta[i][b].first]=
					min(mp[sta[i][a].first][sta[i][b].first],
					sta[i][a].second+sta[i][b].second);
				mp[sta[i][b].first][sta[i][a].first]=
					min(mp[sta[i][b].first][sta[i][a].first],
					sta[i][a].second+sta[i][b].second);
			}
		}
	}
	for(long long i=1;i<=n;i++)for(long long j=1;j<=n;j++){
		if(mp[i][j]!=9e18 and i!=j) s[i].push_back(j);
	}
	for(long long i=1;i<=n;i++){dfs(i);}
	for(long long i=1,u,v;i<=q;i++){
		long long ans=9e18;
		cin>>u>>v;
		for(auto nowx:sta[u])for(auto nowv:sta[v]){
			long long linev=nowv.first,cv=nowv.second;
			long long linex=nowx.first,cx=nowx.second;
			ans=min(dist[linev][linex]+cx+cv,ans);
		}
		cout<<ans+w[u]+w[v]<<'\n';
	}
	return;
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	solve();
	return 0;
}