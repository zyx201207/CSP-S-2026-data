#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q,w[500005],dp[505][505];
vector<pair<long long,long long> > dt[500005];
stack<long long> hc;
void Floyd(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dp[i][k]==0||dp[k][j]==0||i==j) continue;
				if(dp[i][k]+dp[k][j]<dp[i][j]){
					dp[i][j]=dp[i][k]+dp[k][j];
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		long long k;
		cin>>k;
		for(int j=1;j<=k;j++){
			long long x,y;
			cin>>x>>y;
			if(!dt[x].empty()) hc.push(x);
			dt[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
	}
	for(int i=1;i<=n;i++) dp[i][i]=0;
	while(!hc.empty()){
		long long id=hc.top();
		hc.pop();
		for(int i=0;i<dt[id].size();i++){
			for(int j=i+1;j<dt[id].size();j++){
				long long u=dt[id][i].first,v=dt[id][j].first,w=dt[id][i].second+dt[id][j].second;
				dp[u][v]=w;
				dp[v][u]=w;
			}
		}
	}
	Floyd();
	for(int QQ=1;QQ<=Q;QQ++){
		long long x,y,minn=1e18;
		cin>>x>>y;
		for(int i=0;i<dt[x].size();i++){
			for(int j=0;j<dt[y].size();j++){
				long long xdt=dt[x][i].first,ydt=dt[y][j].first;
				minn=min(minn,w[x]+w[y]+dt[x][i].second+dt[y][j].second+dp[xdt][ydt]);
			}
		}
		cout<<minn<<"\n";
	}
	return 0;
} 
