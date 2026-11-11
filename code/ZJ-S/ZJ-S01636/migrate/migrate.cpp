#include <bits/stdc++.h>
#define ll long long
#define vec vector
#define sca scanf
#define pri printf
using namespace std;
const int N=2e6+100;
const int NN=5e3+10;
ll c,t,n,d,ans;
ll a[N];
ll dp[NN][NN];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	sca("%d%d",&c,&t);
	while(t--){
		sca("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++){
			sca("%lld",&a[i]);
			dp[i][i]=1;
		}
		for(int k=1;k<=n-1;k++){
			for(int i=1,j;i<=n-k;i++){
				j=i+k;
				if(a[j]-a[i]<=d)dp[i][j]++;
				for(int p=i+1;p<j;p++){//jump
					if(a[p]-a[p-1]<=d){
						dp[i][j]+=dp[i][p-1]*dp[p][j];
					}
				}
			}
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				pri("%d ",dp[i][j]);
			}
			pri("\n");
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(dp[i][j]==2)ans++;
			}
		}
		pri("%lld\n",ans);
	}
	return 0;
}