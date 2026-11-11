#include<bits/stdc++.h>
//#define int long long
#define ll long long
#define endl '\n'
using namespace std;
const int N=2e6+5,M=505;
const ll inf=1e18;
int c,T,n,k,dep[N],faa[N],anss[N];
vector<int> g[N];
bool f[N];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	for(auto v:g[u]){
		if(v!=fa) dfs(v,u);
	}
}
int find(int x){
	return (x==faa[x])?x:(faa[x]=find(faa[x]));
}
int lca(int x,int y){
	return 0;
}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++) faa[i]=i;
	for(int i=1;i<=n;i++) anss[i]=inf;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1,0);
	for(ll i=0;i<(1<<n);i++){
		int ppcnt=0,cnt=0,j=i;
		while(j){
			if(j%2) ppcnt++;
			f[++cnt]=j%2;
			j>>=1; 
		}
		for(int jj=1;jj<=n;jj++) faa[jj]=jj;
		int ccnt=n;
		if(ppcnt==k){
			for(int jj=1;jj<=n;jj++){
				if(f[jj]){
					for(auto vv:g[jj]){
						if(find(vv)!=find(jj)){
							faa[vv]=find(jj);
							ccnt--;
						}
					}
				}
			}
			if(ccnt==n-k+2){
				for(int ii=1;ii<=n;ii++){
					for(int jj=1;jj<=n;jj++){
						if(f[jj]){
							anss[ii]=min(anss[ii],dep[ii]+dep[jj]-2*lca(ii,jj));
						}
					}
				} 
			}
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}

