#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
32pts~24pts
*/

const int N=2e6+10,MINN=5010;
int c,t;
int n,d,x[N];
//n<=5100,用区间DP
pair<int,int> dp[MINN][MINN];//从l飞到r的最短距离、方案数
int f[N];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%lld%lld",&c,&t);
	if(c<=10){
		while(t--){
			scanf("%lld%lld",&n,&d);
			memset(dp,0x3f,sizeof(dp));
			for(int i=1;i<=n;i++){
				scanf("%lld",&x[i]);
				if(i>1&&x[i]-x[i-1]<=d){
					dp[i-1][i].first=1;
					dp[i-1][i].second=1;
				}
			}
			
			for(int len=3;len<=n;len++){
				for(int l=1;l<=n-len+1;l++){
					int r=l+len-1;
					if(x[r]-x[l]<=d){
						dp[l][r].first=1;
						dp[l][r].second=1;
						continue;
					}
					for(int k=r-1;k>=l;k--){
						if(x[r]-x[k]<=d){
							if(dp[l][r].first>dp[l][k].first+1){
								dp[l][r].first=dp[l][k].first+1;
								dp[l][r].second=dp[l][k].second;
							}else if(dp[l][r].first==dp[l][k].first+1){
								dp[l][r].second+=dp[l][k].second;
							}
						}else break;
					}
				}
			}
			
			int ans=0;
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(dp[i][j].second==2){
						ans++;
					}
				}
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	//特殊性质A
	if(c>=11&&c<=12){
		while(t--){
			scanf("%lld%lld",&n,&d);
			if(n<=3){
				printf("0\n");
				continue;
			}
			for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
			int maxn=d/(x[2]-x[1]),ans=0;
			n--;
			if(n<=maxn||maxn<=1||d>=(x[n]-x[1])) ans=0;
			else if(n<=2*maxn-2){
				ans=0;
			}else{
				ans=n-maxn*2+2;
			}
			printf("%lld\n",ans);
		}
		return 0;
	}
	return 0;
}