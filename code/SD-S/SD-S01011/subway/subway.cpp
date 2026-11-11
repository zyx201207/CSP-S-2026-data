#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pii pair<int,int>
using namespace std;
const int M=510;
const int N=5e5+10;
const ll LL_INF=0x3f3f3f3f3f3f3f3f;
ll w[N];
ll dp[M][M];
vector<pii> G[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr); 
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++){
		dp[i][i]=0;
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			G[x].push_back(mp(i,y));
		}
	}
	for(int i=1;i<=m;i++){
		int len=G[i].size();
		for(int j=0;j<len;j++){
			int a=G[i][j].first;
			int x=G[i][j].second;
			for(int k=0;k<len;k++){
				int b=G[i][k].first;
				int y=G[i][k].second;
				dp[a][b]=min(dp[a][b],(ll)(x+y));
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
	while(q--){
		int a,b;
		cin>>a>>b;
		ll ans=LL_INF;
		for(auto i:G[a]){
			int x=i.first;
			int u=i.second;
			for(auto j:G[b]){
				int y=j.first;
				int v=j.second;
				ans=min(ans,w[a]+w[b]+u+v+dp[x][y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
