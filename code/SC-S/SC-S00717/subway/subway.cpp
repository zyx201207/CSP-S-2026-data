#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,son[505];
ll dp[505][505],w[500005];//dp[i][j]:从i线路到j线路的最小换乘时间
vector<pair<int,ll> > mp[500005];
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>son[i];
		//途径地铁站书
		for(int j=1;j<=son[i];j++){
			int u;
			ll v;
			cin>>u>>v;
			//u:地铁站编号 v:步行时间
			mp[u].push_back({i,v});
		}
	}
	//初始化
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=2e18;
		}
		dp[i][i]=0;//从i到i
	}
	//建图
	for(int i=1;i<=m;i++){
		int l=mp[i].size();
		for(int j=0;j<l;j++){
			for(int k=0;k<l;k++){
				if(j==k) continue;
				int u=mp[i][j].first,v=mp[i][k].first;
				ll tw=mp[i][j].second+mp[i][k].second;
				dp[u][v]=min(dp[u][v],tw);
				dp[v][u]=min(dp[v][u],tw);
			}
		}
	}
	//Floyd
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j||j==k||i==k) continue;
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	//查询
	for(int i=1;i<=q;i++){
		int x,y;
		ll ans=2e18;
		cin>>x>>y;
		int l1=mp[x].size(),l2=mp[y].size();
		for(int j=0;j<l1;j++){
			for(int k=0;k<l2;k++){
				int u=mp[x][j].first,v=mp[y][k].first;
				int wu=mp[x][j].second,wv=mp[y][k].second;
				ans=min(ans,w[x]+w[y]+dp[u][v]+wu+wv);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}