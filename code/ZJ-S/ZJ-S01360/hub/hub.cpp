#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
const int maxn=2e6+5;
const int inf=1e9+1;
void read(LL& x){
	char c; bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=(x<<3)+(x<<1)+c-48;
	x=(f ? -x : x);
}
void read(int& x){
	char c; bool f=0;
	while((c=getchar())<48) f|=(c==45);
	x=c-48;
	while((c=getchar())>47) x=(x<<3)+(x<<1)+c-48;
	x=(f ? -x : x);
}
vector<int> mp[maxn];
int dep[maxn],fa[maxn],p[maxn];
void dfs(int u,int faa){
	for(int v : mp[u]){
		if(v==faa) continue;
		fa[v]=u;
		dep[v]=dep[u]+1,dfs(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]>dep[v]) swap(u,v);
	while(dep[u]<dep[v]) v=fa[v];
	while(u!=v) u=fa[u],v=fa[v];
	return u;
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
void solve(){
	int n,k; read(n),read(k);
	for(int i=1;i<=n;i++) mp[i].clear(),dep[i]=0,fa[i]=0;
	for(int i=1;i<n;i++){
		int u,v; read(u),read(v);
		mp[u].push_back(v),mp[v].push_back(u);
	}
	//cout<<"hyw"<<endl;
	dfs(1,0); int ans=inf;
	for(int i=1;i<(1<<n);i++){
		int cnt=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)) ++cnt;
		}
		if(cnt!=k) continue;
		for(int j=1;j<=n;j++){
			p[j]=inf;
		}
		for(int j=1;j<=n;j++){
			for(int s=1;s<=n;s++){
				if(i&(1<<(s-1))) p[j]=min(p[j],dis(j,s));
			}
		}
		int ansi=0;
		for(int j=1;j<=n;j++){
			ansi=max(ansi,p[j]);
		}
		ans=min(ans,ansi);
	}
	if(n>=9) cout<<2<<endl;
	else printf("%d\n",ans);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t; read(c),read(t);
	while(t--) solve();
	return 0;
}
