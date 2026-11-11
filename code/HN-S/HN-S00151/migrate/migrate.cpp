#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ull unsigned long long

int const N=2e6+10;
int n,d,pos[N],dis[N],f[N],ans;
bool vis[N];
vector<int> g[N];

void BFS(int s){
	queue<int> q;
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	memset(f,0,sizeof f);
	q.push(s),dis[s]=0,f[s]=1;
	while(q.size()){
		int u=q.front();q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:g[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				f[v]=f[u];
				q.push(v);
			}
			else if(dis[v]==dis[u]+1) f[v]+=f[u];
		}
	}
	return ;
}

void solve(){
	cin>>n>>d;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		cin>>pos[i];
		for(int j=i-1;j>=1;j--){
			if(pos[i]-pos[j]>d) break;
			g[j].push_back(i);
		}
	}
	ans=0;
	for(int i=1;i<=n;i++){
		BFS(i);
		for(int j=i+1;j<=n;j++) ans+=(f[j]==2);
	}
	cout<<ans<<"\n";
	return ;
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int C,T=1;
	cin>>C>>T;
	while(T--) solve();
	return 0;
}
