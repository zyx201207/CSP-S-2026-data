#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;
const int N=1e6+10;
int c,t;
int n,k;
vector<int>g[N];
bool vis[N];
void dfs(int x,ll msk){
	vis[x]=1;
	for(auto i:g[x]){
		if(!vis[i] && ((msk>>i-1)&1)){
			dfs(i,msk);
		}
	}
	return;
}
int dis[N];
void get(int x,int stp,int fa){
	if(stp>=dis[x]){
		return;
	}
	dis[x]=stp;
	for(auto i:g[x]){
		if(i==fa){
			continue;
		}
		get(i,stp+1,x);
	}
	return;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==7){
		while(t--){
			int ans=0x3f3f3f3f;
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;
				cin>>u>>v;
				g[u].emplace_back(v);
				g[v].emplace_back(u); 
			}
			if(k==1){
				for(int i=1;i<=n;i++){
					int now=0;
					for(int j=1;j<=n;j++){
						dis[j]=0x3f3f3f3f;
	//					cout<<j<<' '<<((i>>j-1)&1)<<endl;
					} 
					get(i,0,0);
					for(int j=1;j<=n;j++){
	//					cout<<j<<' '<<dis[j]<<endl;
						now=max(now,dis[j]);
					}
					ans=min(ans,now);
				}
			}else{
				for(int i=1;i<n;i++){
					for(int j=i+1;j<=n;j++){
						int now=0;
						for(int k=1;k<=n;k++){
							dis[k]=0x3f3f3f3f;
		//					cout<<j<<' '<<((i>>j-1)&1)<<endl;
						} 
						get(i,0,0);
						get(j,0,0);
						for(int k=1;k<=n;k++){
		//					cout<<j<<' '<<dis[j]<<endl;
							now=max(now,dis[k]);
						}
						ans=min(ans,now);
					}
				} 
			}
			cout<<ans<<endl;
			for(int i=1;i<=n;i++){
				g[i].clear();
			} 
		} 
		return 0;
	}
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].emplace_back(v);
			g[v].emplace_back(u); 
		} 
		int ans=0x3f3f3f3f;
		for(ll i=0;i<(1ll<<n);i++){
			int cnt=0,cntt=0;
			for(int j=1;j<=n;j++){
				if(((i>>j-1))&1){
					cntt++;
				}
				if(!vis[j] && ((i>>j-1)&1)){
					cnt++;
					dfs(j,i);
				}
			}
			for(int j=1;j<=n;j++){
				vis[j]=0;
			} 
			if(cntt==k && cnt==2){
				int now=0;
				for(int j=1;j<=n;j++){
					dis[j]=0x3f3f3f3f;
//					cout<<j<<' '<<((i>>j-1)&1)<<endl;
				} 
				for(int j=1;j<=n;j++){
					if(((i>>j-1)&1)){
						get(j,0,0); 
					}
				}
				for(int j=1;j<=n;j++){
//					cout<<j<<' '<<dis[j]<<endl;
					now=max(now,dis[j]);
				}
				ans=min(ans,now);
			}
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		cout<<ans<<endl;
	}
	return 0;
}
