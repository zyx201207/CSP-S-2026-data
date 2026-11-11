#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5,M=1005;
int c,T;
int n,k,fa[N];
int q[N],h,t;
int dis[N],d[M][M];
vector<int> e[N];
int find(int x){
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
void solve1(){
	int ans=1e18;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)!=k) continue ;
		for(int j=1;j<=n;j++) fa[j]=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1){
				fa[j]=j;
				for(auto v:e[j]){
					int fv=find(v);
					if(!fv) continue ;
					fa[fv]=j; 
				}
			}
		}
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(find(j)==j) cnt++;
		}
		if(cnt>2) continue ;
		h=1,t=0;
		for(int j=1;j<=n;j++){
			if((i>>(j-1))&1) q[++t]=j,dis[j]=0;
			else dis[j]=1e18;
		}
		while(h<=t){
			int u=q[h++];
			for(auto v:e[u]){
				if(dis[u]+1<dis[v]) dis[v]=dis[u]+1,q[++t]=v;
			}
		}
		int res=0;
		for(int j=1;j<=n;j++) res=max(res,dis[j]);
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
}
void solve2(){
	int x=(n+1)/2+1;
	cout<<max(0ll,(x-k-1)/4+1)<<'\n';
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) e[i].clear();
	for(int i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(c<=3) solve1();
	else solve2();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
/*
All right.
Everything have come to an end.
Cannot struggle any more.
Just ACed T1 T2.
T3 and T4 scarcely scored.
I think the difficulties will be:orange, yellow, cyan(maybe blue?), ?
No improvements last year.
Noober and number than 2025.
I was monoqueueing others before, but now the tables have turned.

*/
