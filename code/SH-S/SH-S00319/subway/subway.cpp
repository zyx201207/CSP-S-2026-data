#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],t[505][500005];
long long ans;
bool vis[500005];
vector<pair<int,int>>g[500005];
void dfs(int u,int z,int id,long long s){
    if(u==z){
    	ans=min(ans,s+t[id][u]);
    	return;
	}
	for(auto v:g[u]){
		if(!vis[v.first]){
			vis[v.first]=1;
			if(v.second==id)
				dfs(v.first,z,id,s);
			else
				dfs(v.first,z,v.second,s+t[id][u]+t[v.second][u]);
			vis[v.first]=0;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
		scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k,lst=0;
		scanf("%d",&k);
		while(k--){
			int v,ti;
			scanf("%d%d",&v,&ti);
			t[i][v]=ti;
			if(lst!=0){
				g[lst].push_back(make_pair(v,i));
				g[v].push_back(make_pair(lst,i));
			}
			lst=v;
		}
	}
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ans=1e18;
		dfs(x,y,0,0);
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
