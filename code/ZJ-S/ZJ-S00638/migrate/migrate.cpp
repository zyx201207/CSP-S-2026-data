#include<bits/stdc++.h>
using namespace std;
const int N=5010;
int c,t,n,d,a[N];
pair<int,int>dp[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&d);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dp[i][j]={1<<30,0};
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]),dp[i][i]={0,1};
		sort(a+1,a+n+1);
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int x=lower_bound(a+1,a+j,a[j]-d)-a;
				for(int k=x;k<j;k++){
					if(dp[i][k].first+1<dp[i][j].first)
						dp[i][j]={dp[i][k].first+1,dp[i][k].second};
					else if(dp[i][k].first+1==dp[i][j].first)
						dp[i][j].second+=dp[i][k].second;
				}
				if(dp[i][j].second==2)ans++;
			}
		}
		printf("%d\n",ans);
	}
}
