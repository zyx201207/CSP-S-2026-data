#include<bits/stdc++.h>
#define ll long long 
#define pii pair<int,ll>
#define fi first 
#define se second
using namespace std;
const int N=510,B=500,M=501010;
int n,m,d,q,tot,c;
vector<pii>a[M];
ll dp[N][N],w[M];
void get(ll& x,ll y){x=min(x,y);}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18;
		}
	}
	for(int i=1;i<=m;i++)scanf("%lld",w+i);
	for(int i=1;i<=n;i++){
		int len;
		scanf("%d",&len);
		while(len--){
			int x,y;
			scanf("%d%lld",&x,&y);
			a[x].push_back(make_pair(i,y));
		}
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<a[i].size();j++){
			for(int k=j+1;k<a[i].size();k++){
				int v1=a[i][j].fi,v2=a[i][k].fi;
				get(dp[v1][v2],a[i][j].se+a[i][k].se);
				get(dp[v2][v1],a[i][j].se+a[i][k].se);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		ll ans=1e18;
		scanf("%d%d",&x,&y);
		for(int i=0;i<a[x].size();i++){
			for(int j=0;j<a[y].size();j++){
				ans=min(ans,dp[a[x][i].fi][a[y][j].fi]+a[x][i].se+a[y][j].se);
			}
		}
		printf("%lld\n",w[x]+w[y]+ans);
	}
	return 0;
}

