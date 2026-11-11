#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+15;
int c,T;
int n,k;
bool b[N];
int fa[N];
int dis[127][127];
int ans;
int Find(int x){
	if(fa[x]==x) return x;
	return fa[x]=Find(fa[x]);
}
void solve1(){
	ans=1e18;
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j) dis[i][j]=1e18;
		}
	}
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%lld%lld",&u,&v);
		dis[u][v]=dis[v][u]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(dis[i][j]==1e18) continue;
			for(int k=1;k<=n;k++){
				dis[k][i]=dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
			}
		}
	}
	for(int i=0;i<(1<<n);i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			b[j]=(i>>(j-1))&1;
			cnt+=b[j];
		}
		if(cnt!=k) continue;
		for(int j=1;j<=n;j++) fa[j]=j;
		for(int u=1;u<=n;u++){
			if(!b[u]) continue;
			for(int v=1;v<=n;v++){
				if(u==v||dis[u][v]>1||!b[v]) continue;
				int fu=Find(u),fv=Find(v);
				if(fu==fv) continue;
				fa[fv]=fu;
			}
		}
		vector<int> fj;
		for(int j=1;j<=n;j++){
			if(!b[j]) continue;
			fj.push_back(Find(j));
		}
		sort(fj.begin(),fj.end());
		fj.erase(unique(fj.begin(),fj.end()),fj.end());
		if(fj.size()!=2) continue;
		int resa=0;
		for(int u=1;u<=n;u++){
			if(b[u]) continue;
			int resb=1e18;
			for(int v=1;v<=n;v++){
				if(!b[v]) continue;
				resb=min(resb,dis[u][v]);
			}
			resa=max(resa,resb);
		}
		ans=min(ans,resa);
	}
	printf("%lld\n",ans); 
}
void solve(){
	solve1();
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--) solve();
	return 0;
} 
