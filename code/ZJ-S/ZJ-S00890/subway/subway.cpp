#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
using namespace std;
long long c,n,m,d,qq,w[500010];
vector<pair<long long,long long>> g[1000510];
int main(){
	fast;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		long long x;
		cin>>x;
		for(int j=1;j<=x;j++){
			long long a,t;
			cin>>a>>t;
			g[2*m+i].push_back({a+m,t});
			g[a+m].push_back({2*m+i,t});
		}
	}
	for(int i=m+1;i<=2*m;i++){
		g[i].push_back({i-m,w[i-m]});
		g[i-m].push_back({i,w[i-m]});
	}
	long long dp[2*m+n+5],ans[m+5][m+5];
	for(int i=1;i<=m;i++){
		memset(dp,0x3f,sizeof(dp));
		dp[i]=0;
		priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> q;
		q.push({0,i});
		while(!q.empty()){
			long long y=q.top().second;
			long long x=q.top().first;
			q.pop();
			if(x>dp[y]){
				continue;
			}
			for(auto i:g[y]){
				long long j=i.first;
				long long l=i.second;
				if(dp[y]+l<dp[j]){
					dp[j]=dp[y]+l;
					q.push({dp[j],j});
				}
			}
		}
		for(int j=1;j<=m;j++){
			ans[i][j]=dp[j];
		}
	}
	while(qq--){
		long long a,b;
		cin>>a>>b;
		cout<<ans[a][b]<<endl;
	}
	return 0;
}
