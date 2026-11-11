#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N]; 
vector <int> g[N];
int vis[N];
int bfs(int s,int ed){
	for(int i=1;i<=n;i++){
		vis[i]=-1;
	}
	queue <int> q;
	vis[s]=0;
	q.push(s);
	int ok=0;
	while(!q.empty()){
		auto u=q.front();
//		cout<<u<<"\n";
		q.pop();
		if(u==ed){
			continue;
		}
		for(auto v:g[u]){
			if(v==ed&&(vis[ed]==-1||vis[ed]==vis[u]+1)) ok++;
			if(vis[v]!=-1&&vis[v]<vis[u]+1) continue;
			vis[v]=vis[u]+1;
			q.push(v);
		}
	}
	return ok;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			for(int j=1;j<i;j++){
				if(abs(x[i]-x[j])<=d){
					g[i].push_back(j);
					g[j].push_back(i);
				}
			}
		}
//		for(int i=1;i<=n;i++){
//			cout<<i<<":\n";
//			for(auto v:g[i]){
//				cout<<v<<" ";
//			}
//			puts("");
//		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int tmp=bfs(i,j);
				if(tmp==2){
					cnt++;
				}
			}
		} 
		printf("%lld\n",cnt);
	}
	return 0;
}

