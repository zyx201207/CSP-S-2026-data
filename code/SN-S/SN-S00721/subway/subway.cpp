//准考证号:SN-S00721     姓名:强小轩
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ldb long double
#define eps 1e-7
const int maxn=5e2+10;
const int maxm=6e5+10;
const int mod1=1e9+7;
const int mod2=998244353;
using namespace std;
typedef pair<int,int> Pii;
ll c,n,d,q,w[maxm],dp[maxn][maxn];
int m;
struct edge{
	int to;
	ll cost;
};
vector<edge> G[maxm];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		while(k--){
			int x,y;
			cin>>x>>y;
			G[i+m].push_back({x,y});
			G[x].push_back({i+m,y});
//			cout<<i+m<<' '<<x<<' '<<y<<'\n';
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=1e18L;
		}
		dp[i][i]=0;
	}
	for(int k=1;k<=m;k++){
		for(edge i:G[k]){
			for(edge j:G[k]){
				if(i.to==j.to)continue;
				dp[i.to-m][j.to-m]=dp[j.to-m][i.to-m]=min(dp[i.to-m][j.to-m],i.cost+j.cost);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<i<<' '<<j<<' '<<dp[i][j]<<'\n';
//		}
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int s,t;
		cin>>s>>t;
		ll res=1e18L;
		for(edge i:G[s]){
			for(edge j:G[t]){
				res=min(res,dp[i.to-m][j.to-m]+i.cost+j.cost);
//				cout<<i.to<<' '<<j.to<<' '<<dp[i.to-m][j.to-m]<<' '<<res<<'\n';
			}
		}
		res+=w[s];
		res+=w[t];
		cout<<res<<'\n';
	}
	return 0;
} 
























