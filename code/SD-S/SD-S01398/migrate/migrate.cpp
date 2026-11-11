#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,T,n,d,a[2000010],vis[2000010][2],ans=0,viss[2000010];
vector<int>g[2000010];
void bfs(int start){
	ll minn=0x3f3f3f3f;
	memset(vis,0,sizeof(vis));
	for(int i=0;i<2000010;i++) vis[i][0]=0x3f3f3f3f;
	queue<array<int,2>>q;
	q.push({start,0});
	while(!q.empty()){
		int u=q.front()[0],t=q.front()[1];
		q.pop();
		if(vis[u][0]>t){
			vis[u][0]=t;
			vis[u][1]=1;
		}else if(vis[u][0]==t) vis[u][1]++;
		for(auto &v:g[u]){
			if(v<=n&&!viss[v]){q.push({v,t+1});viss[v]=1;}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i][1]==2) ans++;
	}
}
void solve(){
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]-a[j]<=d) g[j].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		memset(viss,0,sizeof viss);
		bfs(i);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*ToT*/
