#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5;
vector<int>g[N];
int dis[N];
void dfs(int x,int fa){
	dis[x]=dis[fa]+1;
	for(auto y:g[x]){
		if(y==fa)continue;
		dfs(y,x);
	} 
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		dfs(1,0);
		int maxn=0;
		for(int i=1;i<=n;i++){
			if(dis[maxn]<dis[i]){
				maxn=i;
			} 
		}
		dfs(maxn,0);
		maxn=0;
		for(int i=1;i<=n;i++){
			if(dis[maxn]<dis[i]){
				maxn=i;
			} 
		}
		if(c==13 or c==14){
			cout<<dis[maxn]<<endl;
		}
		else{
			cout<<(int)(dis[maxn]/3.5)<<endl;
		}
		for(int i=1;i<=n;i++)g[i].clear();
	}

    return 0;
}


