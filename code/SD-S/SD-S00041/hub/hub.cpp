#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<ll,ll>
#define p(i,j) make_pair(i,j)
#define DEBUG_CODE 0
#define NDB if(!DEBUG_CODE)
#define DB if(DEBUG_CODE)
using namespace std;
const int N=2e6+10;
const int mod=1e9+7;
ll n,m,x,y,z,sum,ans,cnt,tot,k,T,u,v,w,l,r,opt,a[N],c,f[N][25],dep[N];
vector<int> e[N];
void dfs1(int u,int fa){//对a=2连通块写0 
	if(!a[u]) return ;
	a[u]=1;
	for(auto v:e[u]){
		if(v!=fa&&a[v]==2){
			dfs1(v,u);
		}
	}
}
void dfs2(int u,int fa){//求dep,fa 
	dep[u]=dep[fa]+1;
	f[u][0]=fa;
	for(auto v:e[u]) if(v!=fa) dfs2(v,u);
}
int lca(int u,int v){
	if(u==v) return u;
	if(dep[u]<dep[v]) swap(u,v);
	if(dep[u]!=dep[v]){
//		cout<<"?";
		for(int i=22;i+1;i--) if(dep[f[u][i]]>dep[v]) u=f[u][i];//cout<<"!"<<u<<"!";
		u=f[u][0];
	}
//	cout<<u<<" "<<v<<"\n";
	if(u==v) return u;
	for(int i=22;i+1;i--) if(f[u][i]!=f[v][i]) u=f[u][i],v=f[v][i];
	return f[u][0];
}
ll dis(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	if(lca(u,v)==v) return dep[u]-dep[v];
	return dep[u]+dep[v]-(dep[lca(u,v)]<<1);
}
int main(){
	NDB{
		ios::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	}
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
//	T=1;
	while(T--){
		cin>>n>>m;
		ans=mod;
		for(int i=1;i<=n;i++) e[i].clear(),dep[i]=0;
		for(int i=1;i<n;i++) cin>>u>>v,e[u].push_back(v),e[v].push_back(u);
		for(int j=1;j<=22;j++) for(int i=1;i<=n;i++) f[i][j]=0;
		dfs2(1,1);
		for(int j=1;j<=22;j++) for(int i=1;i<=n;i++) f[i][j]=f[f[i][j-1]][j-1];
//		cin>>x;
//		while(x--){
//			cin>>u>>v;
//			cout<<lca(u,v)<<" "<<dep[u]<<" "<<dep[v]<<"\n";
//		}
		for(int sta=0;sta<(1<<n);sta++){
			cnt=0;
			for(int j=0;j<n;j++) if((sta>>j)&1) cnt++;
			if(cnt==m){
				cnt=0;
				for(int i=1;i<=n;i++) a[i]=((sta>>(i-1))&1)<<1;
				for(int i=1;i<=n;i++) if(a[i]==2) cnt++,dfs1(i,0);
				if(cnt<=2){
//					DB for(int i=1;i<=n;i++) if(a[i]) cout<<i<<" ";
//					DB cout<<"\n";
					ll pans=0;
					for(int i=1;i<=n;i++){
						sum=mod;
						if(a[i]) sum=0;
						else{
							for(int j=1;j<=n;j++){
								if(a[j]){
									sum=min(sum,dis(i,j));
//									if(a[1]&&a[4]) cout<<i<<" "<<j<<" "<<dis(i,j)<<"\n";
								}
							}
						}
//						if(a[1]&&a[4]) cout<<sum<<"\n";
						pans=max(pans,sum);
					} 
					ans=min(ans,pans);
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
/*
1 1
8 1
1 2
2 3
3 4
3 5
1 6
6 7
6 8
5
*/
