#include<bits/stdc++.h>
using namespace std;

const int MAXN=2e6+27;

int n,k;
int maxn[MAXN],dep[MAXN];
vector<int> g[MAXN];

inline void dfs(int u,int from){
	dep[u]=dep[from]+1;
	maxn[u]=0;
	for(auto v:g[u]){
		if(v==from) continue;
		dfs(v,u);
		maxn[u]=max(maxn[u],maxn[v]+1);
	}
	return ;
}

int main(){
	
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		if(k<=2){
			int rem=0,ind=1;
			for(int i=1;i<=n;i++){
				if(dep[i]>rem){
					rem=dep[i];
					ind=i;
				}
			}
			dfs(ind,0);
			rem=0;
			for(int i=1;i<=n;i++)
				rem=max(rem,dep[i]);
			cout<<rem/3<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	
	return 0;
}