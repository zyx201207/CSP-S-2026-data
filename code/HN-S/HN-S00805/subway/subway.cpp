//14 41 7/7 100pts
#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int M=5e5+5,N=500+5;
int c,n,m,d,q,w[M],dp[N][N];
struct node{
	int l,t;
};
vector<node> sta[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			if(sta[a].size()){
				for(node x:sta[a]){
					int l=x.l,ot=x.t;
					dp[i][l]=min(dp[i][l],t+ot);
					dp[l][i]=min(dp[l][i],t+ot);
				}
			}
			sta[a].push_back({i,t});
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		int ans=1e18;
		for(node nx:sta[x]){
			for(node ny:sta[y]){
				int xl=nx.l,xt=nx.t,yl=ny.l,yt=ny.t;
				ans=min(ans,w[x]+w[y]+xt+yt+dp[xl][yl]);
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

