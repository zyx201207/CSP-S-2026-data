#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,k,c,d,t,vis[500010],dis[510],x[100010],cnt[100010],dp[100010],sum=0,ans=0;
vector<int>vec[500010];
int f=0;
int dfs(int u,int pre,int d){
	if(vis[u])f=d;
	if(f!=0)return f;
	for(auto v:vec[u]){
		if(v==pre)continue;
		dfs(v,u,d+1);
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		memset(x,0,sizeof(x));
		memset(cnt,0,sizeof(cnt));
		memset(dis,0x3f,sizeof(dis));
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			vec[u].push_back(v);
			vec[v].push_back(u);
		}
		int ans=INT_MAX;
		for(int i=0;i<(1<<n);i++){
			memset(vis,0,sizeof(vis));
			int sum=0;
			for(int j=1;j<=n;j++){
				if(i>>(j-1)&1)vis[j]=1,sum++;
			}
			if(sum!=k)continue;
			int ma=0;
			for(int j=1;j<=n;j++){
				f=0;
				ma=max(ma,dfs(j,0,1));
			}
			ans=min(ans,ma);
		}
		cout<<ans<<endl;
	}
	return 0;
}
