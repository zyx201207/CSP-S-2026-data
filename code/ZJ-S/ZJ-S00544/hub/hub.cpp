#include<bits/stdc++.h>
using namespace std;
const int maxn=3005;
vector<int> g[maxn],vv[maxn];
vector<int> v1;
int vis[maxn],dis[maxn];
int cnt=0,n,k;
map<int,int> mp;
void dfs(int u,int fa){
	vis[u]=cnt;
	vv[cnt].push_back(u);
	for(auto v:g[u]){
		if(v!=fa){
			dis[v]=dis[u]+1;
			dfs(v,u);	
		}
	}
}
bool check(int x){
	int ans=0x3f3f3f3f;
	for(int i=1;i<=cnt;i++){
		for(auto u:vv[cnt]){
			for(auto v:vv[cnt]){
				if(u==v) continue;
				ans=min(dis[u]+dis[v],ans);
			}
		}
	}
	if(ans<=x) return 1;
	return 0;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v; 
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				cnt++;
				dfs(i,0);
			}
		}
		int l=0,r=n,res=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid)){
				res=mid;
				r=mid-1;
			}
			else l=mid+1;
		}
		cout<<res<<"\n";
	}        
	return 0;
}
	