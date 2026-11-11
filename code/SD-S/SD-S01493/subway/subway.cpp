#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long T, c, n, m, d;
long long st, ed;
long long k[N], w[N], x;
long long ans;
long long use[N];
long long head[N], nxt[N], to[N], tot;
vector<long long> h[N];
map<long long,long long> a[N], t[N];
map<long long,bool> vis[N];
void add(long long u, long long v){
	nxt[++tot]=head[u];
	to[tot]=v;
	head[u]=tot;
	return;
}
void dfs(long long u, long long res, long long op){
	if(u==ed){
		res+=t[op][u]+w[u];
		ans=min(ans,res);
		return;
	}
	for(long long i=head[u],v;i;i=nxt[i]){
		v=to[i];
		if(use[v])
			continue;
		use[v]=true;
		for(auto p:h[u]){
			if(!vis[v][p])
				continue;
			if(p==op)
				dfs(v,res,op);
			else
				dfs(v,res+t[op][u]+t[p][u],p);
		}
		use[v]=false;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&T);
	for(long long i=1;i<=m;i++)
		scanf("%lld",&w[i]);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(long long j=1;j<=2*k[i];j++){
			scanf("%lld",&x);
			if(j%2==1)
				a[i][j/2+1]=x;
			else
				t[i][a[i][j/2]]=x;
		}
	}
	for(long long i=1;i<=n;i++)
		for(long long j=1;j<=k[i];j++){
			h[a[i][j]].push_back(i);
			vis[a[i][j]][i]=true;
			if(j>1)
				add(a[i][j-1],a[i][j]);
		}
	while(T--){
		cin>>st>>ed;
		ans=1e18;
		for(auto p:h[st])
			dfs(st,w[st]+t[p][st],p);
		if(ans==1e18){
			swap(st,ed);
			for(auto p:h[st])
				dfs(st,w[st]+t[p][st],p);
		}
		printf("%lld\n",ans);
	}
	return 0;
} 
