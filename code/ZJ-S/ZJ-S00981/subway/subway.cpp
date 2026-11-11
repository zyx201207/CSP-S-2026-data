#include <bits/stdc++.h>
using namespace std;
const int M=5e5;
int w[M+10];
vector<int>v[M+10];
long long dp[510][510];
vector<int>t[M+10];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++) scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			int a;
			int tt;
			scanf("%d%d",&a,&tt);
			v[a].push_back(i);
			t[a].push_back(tt);
		}
	}
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++) dp[i][i]=0;
	for(int i=1;i<=m;i++){
		for(int j=0;j<v[i].size();j++){
			for(int k=0;k<v[i].size();k++){
				if((long long)(t[i][j]+t[i][k])<dp[v[i][j]][v[i][k]]) dp[v[i][j]][v[i][k]]=(long long)(t[i][j]+t[i][k]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				if(dp[i][k]+dp[k][j]>=0&&dp[i][j]>dp[i][k]+dp[k][j]) dp[i][j]=dp[i][k]+dp[k][j];
			}
		}
	}
	int x,y;
	while(q--){
		scanf("%d%d",&x,&y);
		long long ans=9000000000000000000;
		for(int i=0;i<t[x].size();i++){
			for(int j=0;j<t[y].size();j++){
				long long tt=t[x][i]+t[y][j]+w[x]+w[y];
				tt+=dp[v[x][i]][v[y][j]];
				if(ans>tt) ans=tt;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}