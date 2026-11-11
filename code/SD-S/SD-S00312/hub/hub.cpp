#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using Pii=pair<int,int>;
using _i128=__int128;
using ull=unsigned long long;
const int maxN=1e6+10;
LL c,T;
//LL n,k; 
//LL tq[maxN],ans;
vector<int> g[maxN];
//set<int> xz;
//bool vis[maxN],lt;
//LL getdist(int x){
//	
//}
//void dfs(){
//	if(xz.size()==k){
//		int t=0;
//		for(int i=1;i<=n;i++)
//			t=max(getdist(i),ans);
//		ans=min(ans,t);
//		return;
//	}
//	for(int i=1;i<=n;i++){
//		if(!vis[i]&&(lt||xz.find())){
//			
//		}
//	}
//}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		LL n,k;
		cin>>n>>k;
//		memset(vis,0,sizeof(vis));
//		for(int i=1;i<=n;i++) g[u].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
//		ans=0x7fffffff;
//		lt=1;
//		dfs();
//		cout<<ans<<'\n';
		cout<<ceil(1.0*(n-k)/4)<<'\n';
	}
	return 0;
}
//EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE
//Ahhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh
