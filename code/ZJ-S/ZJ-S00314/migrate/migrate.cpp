#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000;
const int MAXM=2e6+5;
const long long inf=1e18;
long long x[MAXN],dp[MAXN][MAXN],w[MAXN][MAXN];
long long ans;
int n;
long long d;
void init(){
	memset(x,sizeof(x),0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			dp[i][j]=0;
			if(i==j) w[i][j]=0;
			else w[i][j]=inf;
		}
	}
	ans=0;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		init();
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				int k=j-1;
				while(k>=i && x[j]-x[k]<=d){
					int tmpw=w[i][k]+1;
					if(tmpw<w[i][j]){
						w[i][j]=tmpw;
						dp[i][j]=1;
					}
					else if(tmpw==w[i][j]) dp[i][j]++;
					else continue;
					k--;
				}
				if(dp[i][j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
