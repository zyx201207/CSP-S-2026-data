#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,a,b,ge,to;
long long chuzhan[500500],val,dp[550][550];
struct node{
	int dao;
	long long zhi;
};
vector<node> vec[500500];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++){
		cin>>chuzhan[i];
	}
	for(int i = 1;i<=n;i++){
		cin>>ge;
		for(int j = 1;j<=ge;j++){
			cin>>to>>val;
			vec[to].push_back({i,val});
		}
	}
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=n;j++){
			dp[i][j] = 1e18;
		}
		dp[i][i] = 0;
	}
	for(int i = 1;i<=m;i++){
		int nn = vec[i].size();
		for(int j = 0;j<nn;j++){
			for(int k = 0;k<nn;k++){
				if(j==k){
					dp[vec[i][j].dao][vec[i][k].dao] = 0;
				}else{
					dp[vec[i][j].dao][vec[i][k].dao] = min(dp[vec[i][j].dao][vec[i][k].dao],vec[i][j].zhi+vec[i][k].zhi);
				}
			}
		}
	}
	for(int k = 1;k<=n;k++){
		for(int i = 1;i<=n;i++){
			for(int j = 1;j<=n;j++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		cin>>a>>b;
		int nn = vec[a].size(),mm = vec[b].size();
		long long ans = 1e18;
		for(int j = 0;j<nn;j++){
			for(int k = 0;k<mm;k++){
				ans = min(ans,dp[vec[a][j].dao][vec[b][k].dao]+vec[a][j].zhi+vec[b][k].zhi);
			}
		}
		cout<<ans+chuzhan[a]+chuzhan[b]<<endl;
	}
	return 0;
}

