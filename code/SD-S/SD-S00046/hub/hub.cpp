#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using ldb=long double;
using db=double;
using i128=__int128;
using uint=unsigned int;
using ull=unsigned long long;
int c,t;
int n,k;
const int N_123=10;
vector<int> x_graph[N_123+2];
struct E{
	int u,v;
};
E bian[N_123+2];
bitset<N_123+2> vis;
int f[N_123+2];
int find_f(int x){
	if(f[x]==x){
		return x;
	}
	return f[x]=find_f(f[x]);
}
bool check(){
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	int hebing_cnt=0;
	for(int i=1;i<n;i++){
		if(vis[bian[i].u]&&vis[bian[i].v]){
			int uu=find_f(bian[i].u);
			int vv=find_f(bian[i].v);
			if(uu!=vv){
				f[uu]=vv;
				hebing_cnt++;
			}
		}
	}
	if(k-hebing_cnt<=2){
		return true;
	}
	return false;
}
ll dfs(int x,int y,ll dep){
	if(vis[x]){
		return dep;
	}
	ll minn=1e18;
	for(auto it:x_graph[x]){
		if(it==y){
			continue;
		}
		ll op=dfs(it,x,dep+1);
		minn=min(minn,op);
	}
	return minn;
}
void t_solve(){
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		x_graph[u].push_back(v);
		x_graph[v].push_back(u);
		bian[i].u=u;
		bian[i].v=v;
	}
	ll ans=1e18;
	for(int i=0;i<(1<<n);i++){
		if(__builtin_popcount(i)==k){
			vis.reset();
			for(int j=0;j<n;j++){
				if((1<<j)&i){
					vis[j+1]=1;
				}
			}
			if(check()){
				ll res=0;
				for(int j=1;j<=n;j++){
					ll opt=dfs(j,j,0);
					res=max(res,opt);
				}
				ans=min(ans,res);
			}
		}
	}
	cout<<ans<<'\n';
} 
void t_clear(){
	for(int i=1;i<=n;i++){
		x_graph[i].clear();
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--){
		t_solve();
		t_clear();
	}
	return 0;
}

