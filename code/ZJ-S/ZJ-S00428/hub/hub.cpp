#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,x,y,mx,dp1[1000010],dp2[1000010];
vector<int> e[1000010];
void dfs1(int u,int f){
	dp1[u]=dp1[f]+1;
	mx=max(mx,dp1[u]);
	for(int i:e[u]) if(i!=f) dfs1(i,u);
}
void dfs2(int u,int f){
	dp2[u]=dp2[f]+1;
	mx=max(mx,dp1[u]);
	for(int i:e[u]) if(i!=f) dfs2(i,u);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		mx=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++) e[i].clear();
		for(int i=1;i<n;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		dfs1(1,0);
		int ll=0;
		for(int i=1;i<=n;i++){
			if(dp1[i]==mx){
				ll=i;
				break;
			}
		}
		mx=0;
		dfs2(ll,0);
		cout<<(mx-k-1)/4+1;
	}
	return 0;
}
