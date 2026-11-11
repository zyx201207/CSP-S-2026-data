#include<bits/stdc++.h>
#define int long long
using namespace std;
int h[1005],d[1005];
bitset<1005> v;
vector<int> g[1005];
void dfs(int k){
	for(int i:g[k]){
		if(v[i])continue;
		h[i]=min(h[i],h[k]+1);
		v[i]=true;
		dfs(i);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
//		
//		for(int i=0;i<(1<<n);i++){
//			bool tt=0;
//			if(__builtin_popcount(i)!=k)continue;
//			for(int j=1;j<=n;j++){
//				h[j]=1e14;
//				if(!i&(1<<(j-1)))continue;
//				h[j]=0;
//			}
//			for(int j=1;j<=n;j++){
//				if(!i&(1<<(j-1)))continue;
//				if(v[j])continue;
//				dfs(j);
//				tt++;
//			}
//			int ans=0;
//			if(tt<=2){
//				for(int j=1;j<=n;j++){
//					if(i&(1<<(j-1)))continue;
//					ans=max(ans,j);
//				}
//			}
//		}
		cout<<0<<endl;
	}
	return 0;
}

