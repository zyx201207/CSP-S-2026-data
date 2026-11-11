#include<bits/stdc++.h>
#define fi first
#define se second
#define endl '\n'
#define int long long
using namespace std;
const int inf=LLONG_MAX;
const int maxn=5e5+5;
vector<pair<int,int>> ve[maxn];
int vis[maxn];
vector<int> cnt[maxn];
int w[maxn],k[maxn];
int dis[maxn];
int t[505][1005];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> qu;
int c,n,m,d,T;
void solve(){
	int u,v;
	cin>>u>>v;
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	for(auto i:ve[u]){
		dis[i.fi]=i.se;
		qu.push({i.se,i.fi});
	}
	int ans=inf;
	while(!qu.empty()){
		int now=qu.top().se;
		qu.pop();
		if(vis[now]){
			continue;
		}
		vis[now]=1;
		if(t[now][v]){
			ans=min(ans,dis[now]+t[now][v]);
			continue;
		}
		for(int i:cnt[now]){
			for(auto j:ve[i]){
				if(vis[j.fi]){
					continue;
				}
				if(dis[j.fi]>dis[now]+j.se+t[now][i]){		
					dis[j.fi]=dis[now]+j.se+t[now][i];	
					qu.push({dis[j.fi],j.fi});
				}
			}
		}
	}
	cout<<ans+w[u]+w[v]<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>T;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int l,ti;
			cin>>l>>ti;
			ve[l].push_back({i,ti});
			cnt[i].push_back(l);
			t[i][l]=ti;
		}
	}
	while(T--){
		solve();
	}
	return 0;
}

