#include <bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
const long long LOF=0x3f3f3f3f3f3f3f3f;
int c,n,m,d,q,k[N];
long long w[M],dp[N][N];
vector<int>a[N];
vector<pair<int,long long> >t[M];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)scanf("%lld",&w[i]);
	int aa;
	long long tt;
	for(int i=1;i<=n;i++){
		scanf("%d",&k[i]);
		for(int j=1;j<=k[i];j++){
			scanf("%d%lld",&aa,&tt);
			a[i].push_back(aa),t[aa].push_back({i,tt});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=LOF;
		}
	}
	int n1;
	for(int i=1;i<=m;i++){
		n1=t[i].size();
		for(int j=0;j<n1;j++){
			for(int i1=j+1;i1<n1;i1++){
				dp[t[i][j].first][t[i][i1].first]=dp[t[i][i1].first][t[i][j].first]=t[i][j].second+t[i][i1].second;
			}
		}
	}
	for(int i=1;i<=n;i++)dp[i][i]=0;
	for(int i1=1;i1<=n;i1++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				dp[i][j]=min(dp[i][j],dp[i][i1]+dp[i1][j]);
				dp[j][i]=dp[i][j];
			}
		}
	}
	int q1,q2;
	long long ans=LOF;
	for(int i=1;i<=q;i++){
		scanf("%d%d",&q1,&q2);
		for(auto x:t[q1]){
			for(auto y:t[q2]){
				ans=min(ans,x.second+y.second+dp[x.first][y.first]);
			}
		}
		printf("%lld\n",ans+w[q1]+w[q2]);
		ans=LOF;
	}
	return 0;
}
