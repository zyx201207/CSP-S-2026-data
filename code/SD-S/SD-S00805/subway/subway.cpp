#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<map>
using namespace std;
int c,n,m,d,q;
long long w[500005];
int ma=0;
vector<pair<int,int>> edge[500005];
long long dp[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	memset(dp,0x3f,sizeof(dp));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			edge[a].push_back({i,t});
		}
	}
//	cerr<<"READ\n";
	for(int i=1;i<=m;i++){
		for(int j=0;j<edge[i].size();j++){
			for(int k=j+1;k<edge[i].size();k++){
				dp[edge[i][k].first][edge[i][j].first]=dp[edge[i][j].first][edge[i][k].first]=min(dp[edge[i][j].first][edge[i][k].first],(long long)edge[i][j].second+edge[i][k].second);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
//	cerr<<"INITED\n";
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=5e15;
		for(auto &i:edge[x]){
			for(auto &j:edge[y]){
				ans=min(ans,i.second+j.second+dp[i.first][j.first]);
//				cerr<<i.first<<' '<<j.first<<' '<<i.second<<' '<<j.second<<' '<<dp[i.first][j.first]<<'\n';
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}
