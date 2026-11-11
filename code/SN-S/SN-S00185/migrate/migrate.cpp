#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,ans;
int biao[5005];
int dp[5005][5005];
int minl[5005][5005];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>biao[i];
		ans=0;
		for(int l=0;l<=n;l++)
		    for(int i=1;i+l<=n;i++){
		    	int j=i+l;dp[i][j]=0;
		    	minl[i][j]=1e17;
		    	if(biao[j]-biao[i]<=d){
		    		minl[i][j]=1;dp[i][j]=1;
		    		continue;
				}
		    	for(int k=i+1;k<j;k++){
		    		int yy=minl[i][k]+minl[k][j];
		    		if(yy>minl[i][j]) continue;
		    		if(yy<minl[i][j]){
		    			minl[i][j]=yy;dp[i][j]=0;
					}
					dp[i][j]+=dp[i][k]*dp[k+1][j];
				}
				if(dp[i][j]==2) ans++;
			}
		cout<<ans<<'\n';
	}
	return 0;
}
