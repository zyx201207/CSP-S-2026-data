#include<bits/stdc++.h>
using namespace std;
struct aaa{
	long long v,w;
};
struct bbb{
	long long a,t;
};
long long w[500005];
vector<aaa> g[505];
vector<bbb> a[500005];
long long dp[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long a1,t1;
			cin>>a1>>t1;
			a[a1].push_back({i,t1});
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				g[a[i][j].a].push_back({a[i][k].a,a[i][j].t+a[i][k].t});
				g[a[i][k].a].push_back({a[i][j].a,a[i][j].t+a[i][k].t});
			}
		}
	}
	for(int i=1;i<=n;i++){
	    for(int j=1;j<=n;j++){
	    	dp[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++){
		priority_queue<pair<long long,long long>> q;
		q.push({0,i});
		dp[i][i]=0;
		while(!q.empty()){
			long long w=-q.top().first;
			long long u=q.top().second;
			q.pop();
			if(dp[i][u]<w){
				continue;
			}
			for(auto v:g[u]){
				if(dp[i][v.v]>w+v.w){
					dp[i][v.v]=w+v.w;
					q.push({-dp[i][v.v],v.v});
					//cout<<1;
				}
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		long long ans=1e18;
		for(int i=0;i<a[s].size();i++){
			for(int j=0;j<a[t].size();j++){
				ans=min(ans,w[s]+w[t]+a[s][i].t+a[t][j].t+dp[a[s][i].a][a[t][j].a]);
			}
		}
		cout<<ans<<'\n';
	}
}