#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[1000005],dp[10000][10000];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		int ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			dp[i][i]=1;
		}
		for(int i=1;i<=n;i++){
			for(int j=1+2;j<=n;j++){
				int di=x[j]-x[i];
				for(int z=1;z<=d;z++){
					if(j-z<=0)break;
					dp[i][j]+=dp[i][j-z];
    			}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(dp[i][j]%2==0)ans+=dp[i][j]/2;
			}
		}
		cout<<ans<<endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=0;
			}
		}
	}
	return 0;
}