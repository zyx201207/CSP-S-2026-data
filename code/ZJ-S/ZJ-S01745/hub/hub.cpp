#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int _,T,n,k;
int vis[100010];
vector<int> g[100010];
int S,ans,maxn;
bool check(int i){return S>>(i-1)&1;}
int diss[45][45];
void dis(int u,int fa,int k,int st){
	diss[st][u]=k;
	for(auto v:g[u]){
		if(v==fa) continue;
		dis(v,u,k+1,st);
	}
}
void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	for(auto v:g[u]){
		if(!check(v)||vis[v]) continue;
		dfs(v);
	}
}
int popcount(int x){int sumn=0;for(;x;x-=x&-x,sumn++);return sumn;}
void solve(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ans=1e9;
	for(int i=1;i<=n;i++) dis(i,i,0,i);
	for(S=0;S<(1<<n);S++){
		if(popcount(S)!=k) continue;
		int cnt=0;
		for(int i=1;i<=n;i++) vis[i]=0;
		for(int i=1;i<=n;i++){
			if(check(i)&&!vis[i]){
				cnt++;
				dfs(i);
			}
		}
		if(cnt>2) continue;
		maxn=0;
		for(int i=1;i<=n;i++){
			int minn=1e9;
			if(check(i)) continue;
			for(int j=1;j<=n;j++){
				if(check(j)){
					minn=min(minn,diss[i][j]);
				}
			}			
			maxn=max(maxn,minn);
		}

		ans=min(ans,maxn);
	}
	cout<<ans<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>_>>T;while(T--) solve();
	return 0;
}
/*
Maybe I should AFO
why this contest doesn't take me to the 300pts
25 26 CSPS is to hard
why J is such easy??!
wo yi ji ku

zhi jin dui di tie ni xing ying kong 1h wu fa beng zhu
(nan ren tan qi sheng)
so
AFO in 2026 grade 8

qi xiao le

sus

X X XXX
X X XXX
XX X XXX
XX X XXX
XX X XX XX
XX X XX XX
XX XX X XXX
XX XX X XXX
XX XX X XXX
XX XX X XXX
X X X
X X X
XXX X
XXX X
XXX XXX
XXX XXX
XXXXXXX
XXXXXXX
X X
X X
X X
X X
X 
X
X
X
X
X
X
X
X
X
X
X
X
X
X
(..........)

anyway, if you see this code
guan zhu Idptr xie xie miao
*/

