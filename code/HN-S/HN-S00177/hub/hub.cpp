#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dep[1000005],dk,pd,grent[1000005],cnt,f[1000005]; 
bool z[1000005];
vector<int>G[1000005];
void dfs(int u,int fa){
	dep[u]=dep[fa]+1;
	if(dep[u]>pd){
		pd=dep[u];
		dk=u;
	}
	for(int v:G[u]){
		if(v==fa) continue;
		dfs(v,u); 
	}
}
void dfs2(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	if(G[u].size()==1&&u!=fa) grent[++cnt]=u;
	for(int v:G[u]){
		if(v==fa) continue;
		dfs(v,u); 
	}
}
int up(int u,int yq){
	int hf=0,s=0;
	while(u!=f[u]){
		if(z[u]) return hf;
		if(s>=yq) hf++;
		u=f[u];
		s++;
	}
	if(s!=0) hf++;
	return hf;
}
bool check(int yq){
	fill(z+1,z+1+n,0);
	int lk=k;
	for(int i=1;i<=cnt;i++){
		lk-=up(grent[i],yq);
		if(lk<0) return 0;
	}
	return 1;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0);
	cin>>c>>t;
	while(t--){
		int ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++) G[i].clear();
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1,1);
		fill(dep+1,dep+1+n,0);
		dfs2(dk,dk);
		int l=0,r=dk+1;
		while(l+1<r){
			int mid=(l+r)/2;
			if(check(mid)) ans=mid,r=mid;
			else l=mid;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 
