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
LL x[maxn]; int in[maxn];
LL f[maxn],dis[maxn]; int n; LL d;
vector<int> mp[maxn];
void topo(int x){
	queue<int> q; q.push(x);
	while(!q.empty()){
		int u=q.front(); q.pop();
		for(int v : mp[u]){
			--in[v];
			if(!in[v]) q.push(v);
			if(dis[v]>dis[u]+1){
				f[v]=f[u],dis[v]=dis[u]+1;
			}
			else if(dis[v]==dis[u]+1) f[v]+=f[u];
		}
	}
}
void solve(){
	read(n),read(d);
	for(int i=1;i<=n;i++) read(x[i]);
	LL ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++) in[j]=0,f[j]=0,dis[j]=inf,mp[j].clear(); f[i]=1;
		dis[i]=1;
		for(int j=i;j<=n;j++){
			for(int k=j+1;k<=n;k++){
				if(x[k]-x[j]>d) break;
				mp[j].push_back(k),++in[k];
			}
		}
		topo(i);
		for(int j=i;j<=n;j++) ans+=(f[j]==2);
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; read(c),read(t);
	while(t--) solve();
	return 0;
}