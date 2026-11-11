#include<bits/stdc++.h>
#define pb push_back
#define pob pop_back
#define pf push_back
#define pof pop_back
#define ft first
#define sd second
#define endl '\n'
using namespace std;
int c,t,n,k;
vector<int> edge[110];
bool vis[110];
int ans=INT_MAX;
void dfss(int noww,unordered_map<int,bool> &yong){
	for(auto nex:edge[noww]){
		if(yong[nex]&&!vis[nex]){
			vis[nex]=1;
			dfss(nex,yong);
		}
	}
}
void dfs(int op,unordered_map<int,bool> &yong,vector<int> &yongg){
	if(op==n+1){
		if(yongg.size()!=k){
			return;
		}
		memset(vis,0,sizeof(vis));
		int lian=0;
		for(auto st:yongg){
			if(!vis[st]){
				lian++;
				dfss(st,yong);
			}
			if(lian>2){
				return;
			}
		}
		int dis[110][110];
		memset(dis,0x3f,sizeof(dis));
		for(int i=1;i<=n;i++){
			dis[i][i]=0;
			for(auto nex:edge[i]){
				dis[i][nex]=1;
			}
		}
		for(int kk=1;kk<=n;kk++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][kk]+dis[kk][j]);
				}
			}
		}
		int mx=0;
		for(int i=1;i<=n;i++){
			if(yong[i]){
				continue;
			}
			int mn=INT_MAX;
			for(auto kk:yongg){
				mn=min(mn,dis[i][kk]);
			}
			mx=max(mx,mn);
		}
		ans=min(ans,mx);
		return;
	}
	if(yongg.size()<k){
		for(int i=1;i<=n;i++){
			if(!yong[i]){
				yong[i]=1;
				yongg.pb(i);
				dfs(op+1,yong,yongg);
				yong[i]=0;
				yongg.pob();
			}
		}
	}
	dfs(op+1,yong,yongg);
	return;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			edge[i].clear();
		}
		if(n<=100){
			ans=INT_MAX;
			for(int i=1;i<n;i++){
				int fro,to;cin>>fro>>to;
				edge[fro].pb(to);
				edge[to].pb(i);
			}
			vector<int> yongg;
			unordered_map<int,bool> yong;
			int op=1;
			dfs(op,yong,yongg);
			cout<<ans<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}
	return 0;
}
