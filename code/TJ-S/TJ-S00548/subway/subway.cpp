#include<bits/stdc++.h>
#define int long long
using namespace std;
const int inf=1000000000000000;
struct node{
	int lin,tm;
};
int c,n,m,d,q,k,a,t,vis[500005],w[500005],dp[505][505],x,y;
vector<node>v[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j)dp[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a>>t;
			if(vis[a]){
				for(auto ed:v[a]){
					dp[i][ed.lin]=min(dp[i][ed.lin],t+ed.tm);
					dp[ed.lin][i]=dp[i][ed.lin];
				}
			}
			v[a].push_back({i,t});
			vis[a]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[j][k]=min(dp[j][k],dp[j][i]+dp[i][k]);
			}
		}
	}
	while(q--){
		cin>>x>>y;
		int minn=10000000000000000;
		for(auto st:v[x]){
			for(auto ed:v[y])minn=min(minn,w[x]+w[y]+st.tm+ed.tm+dp[st.lin][ed.lin]);
		}
		cout<<minn<<'\n';
	}
	return 0;
} 
