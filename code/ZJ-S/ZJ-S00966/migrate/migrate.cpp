#include<bits/stdc++.h>
using namespace std;
vector<int> g[4000];
int vis[4000],X[4000];
pair<int,int> dp[4000][4000];
int cnt,ans;
void check(int x,int w,int s){
	if(dp[s][x].second>w) dp[s][x]={1,w};
	else if(dp[s][x].second==w) dp[s][x].first++;
	else return;
	vis[x]=1;
	for(int i=0;i<g[x].size();i++){
		int to=g[x][i];
		if(vis[to])continue;
		check(to,w+1,s);
	}
	vis[x]=0;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;cin>>c;
	int t;cin>>t;
	while(t--){
		ans=0;
		int n,d;cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>X[i];
		}
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=i+1;j<=n;j++){
				if(abs(X[i]-X[j])<=d)g[i].push_back(j);
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]={INT_MAX,INT_MAX};
			}
		}
		for(int u=1;u<=n;u++){
			cnt=0;
			check(u,0,u);
			for(int v=u+1;v<=n;v++)
				if(dp[u][v].first==2)ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}