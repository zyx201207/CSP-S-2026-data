#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e4;
const int INF=0x3f3f3f3f;
int c,n,m,d,q;
ll w[N],dp[N][N];
pair<int,int> a[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	memset(dp,INF,sizeof(dp));
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]);
	for(int i=1;i<=n;i++){
		int x;
		scanf("%d",&x);
		for(int j=1;j<=x;j++) scanf("%d%d",&a[j].first,&a[j].second);
		for(int j=1;j<=x;j++){
			for(int k=j+1;k<=x;k++){
				dp[a[j].first][a[k].first]=a[j].second+a[k].second;
			}
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=i;j<=m;j++){
				dp[j][i]=dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	while(q--){
		int d,e;
		scanf("%d%d",&d,&e);
		cout<<dp[d][e]+w[d]+w[e]<<"\n";
	}
	return 0;
}