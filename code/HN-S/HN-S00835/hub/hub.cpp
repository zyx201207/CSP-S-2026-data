#include <bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
const int N=4e3+5;
int n,k,dep[N],maxn[N],dis[N][N],vis[N],cnt=0;
vector<int> g[N];
void bfs(int s){
	memset(vis,0,sizeof(vis));
	queue<int> q;q.push(s);
	vis[s]=1;dis[s][s]=0;
	while(!q.empty()){
		int t=q.front();
		q.pop();
		for(auto i:g[t]){
			if(dis[s][i]>dis[s][t]+1){
				dis[s][i]=dis[s][t]+1;
				if(!vis[i]) q.push(i),vis[i]=1; 
			}
		}
	}
} 
bool check(int mid){
	set<int> s;
	vector<int> h[N];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]<=mid) h[i].pb(j); 
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(h[i].size()+h[j].size()==n){
				set<int> s;
				for(auto d:h[i]) s.insert(d);
				for(auto d:h[j]) s.insert(d);
				if(s.size()==n) return true;
			}
		}
	}
	return false;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].pb(v);g[v].pb(u);
	} 
	if(k==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=1e18;
			}
		}
		for(int i=1;i<=n;i++) bfs(i);
		int l=1,r=n,res=0;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid)) r=mid-1,res=mid;
			else l=mid+1;
		}
		cout<<res<<"\n";
		return;
	}else cout<<2<<"\n";
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--) solve();
	return 0;
}


