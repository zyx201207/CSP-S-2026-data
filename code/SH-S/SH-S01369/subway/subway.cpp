#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=520,M=5e5+10,INF=9e18;
int c,n,m,d,q;
int w[M],dp[N][N];
vector<int> a[M],t[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1,k;i<=n;i++){
		scanf("%lld",&k);
		for(int j=1,x,y;j<=k;j++){
			scanf("%lld%lld",&x,&y);
			a[x].push_back(i);
			t[x].push_back(y);
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dp[i][j]=INF;
	for(int i=1;i<=m;i++)
		for(int j=0;j<a[i].size();j++)
			for(int k=0;k<a[i].size();k++)
				dp[a[i][j]][a[i][k]]=min(dp[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dp[i][k]<INF&&dp[k][j]<INF)
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	while(q--){
		int x,y,ans=9e18;
		scanf("%lld%lld",&x,&y);
		for(int i=0;i<a[x].size();i++)
			for(int j=0;j<a[y].size();j++)
				if(dp[a[x][i]][a[y][j]]<INF)
					ans=min(ans,t[x][i]+dp[a[x][i]][a[y][j]]+t[y][j]);
		printf("%lld\n",w[x]+ans+w[y]);
	}
	return 0;
}
