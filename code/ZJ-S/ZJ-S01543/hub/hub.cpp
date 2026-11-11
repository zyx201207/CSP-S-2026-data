#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,k,p[15],d[15],vis[15],an,x;
vector<int> e[15];
void DFS(int rt,bool b){
	if(b&&((x>>rt)&1)==0) return;
	if(vis[rt]) return;
	vis[rt]=1;
	for(int i=0;i<e[rt].size();i++){
		if(!b&&e[rt][i]!=p[rt]) p[e[rt][i]]=rt,d[e[rt][i]]=d[rt]+1;
		DFS(e[rt][i],b);
	}
}
int dist(int u,int v){
	if(d[u]<d[v]) return dist(v,u);
	int s=0;
	while(d[u]>d[v]) u=p[u],s++;
	while(u!=v){
		u=p[u];
		v=p[v];
		s+=2;
	}
	return s;
}
void solve(){
	int s=0;
	for(int i=1;i<=n;i++){
		if((x>>i)&1&&!vis[i]){
			s++;
			DFS(i,1);
		}
	}
	if(s>2) return;
	s=0;
	for(int i=1;i<=n;i++){
		int a=1e9;
		for(int j=1;j<=n;j++){
			if((x>>j)&1) a=min(a,dist(i,j));
		}
		s=max(s,a);
	}
	an=min(an,s);
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
			scanf("%lld%lld",&u,&v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		DFS(1,0);
		an=1e9;
		for(x=0;x<(1<<(n+1));x+=2){
			int s=0;
			for(int i=1;i<=n;i++) s+=(x>>i)&1,vis[i]=0;
			if(s==k) solve();
		}
		printf("%lld\n",an);
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}