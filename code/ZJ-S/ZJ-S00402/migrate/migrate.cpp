#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long x[2000010];
long long fa[2000010];
long long vis[2000010];
vector<int> e[2000010];
void bfs(int x){
	queue<int> q;
	q.push(x);
	vis[x]=1;
	fa[x]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:e[u]){
			if(vis[v]){
				if(vis[v]==vis[u]+1) fa[v]+=fa[u];
				continue;
			} 
			vis[v]=vis[u]+1;
			fa[v]=fa[u];
			q.push(v);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++) cin >> x[i];
		if(n>5000){
			if(n==1){
				cout << 0 << '\n';
				continue;
			}
			long long tr=x[2]-x[1];
			if(d<tr*2){
				cout << 0 << '\n';
				continue;
			}
			long long yj=(d/tr)*2-1;
			cout << max(0ll,n-yj) << '\n';
			continue;
		}
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]<=d){
					e[i].push_back(j);
					e[j].push_back(i);
				}
			}
		}
		long long cnt=0;
		for(int i=1;i<=n;i++){
			memset(fa,0,sizeof fa);
			memset(vis,0,sizeof vis);
			bfs(i);
			for(int j=1;j<=n;j++){
				if(fa[j]==2) cnt++;
			}
		} 
		cout << cnt/2 << '\n';
	}
	return 0;
}
