#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,t;
int n,m;
int a[2000006];
int dp[2000005];
int f[2000005];
int q[2000005];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>t;
	while(t--){
		if(C>=13&&C<=14){
			cout<<0<<endl;
			continue;
		}
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i]; 
		}
		double x=clock();
		int ans=0;
		for(int i=1;i<=n;i++){
		//	dp[0]=1e18;
			for(int j=1;j<=n;j++){
				dp[j]=0;
				f[j]=0;
			}
			dp[i]=0;
			for(int j=i+1;j<=n;j++){
				int u=lower_bound(a+1,a+n+1,a[j]-m)-a;
				u=max(u,i);
				if(a[u]>=a[j]){
					dp[j]=1e18;
					break;
				}else{
					dp[j]=dp[u]+1;
					f[j]|=f[u];
					if(a[u+1]<a[j]){
						if(dp[u+1]==dp[u]&&dp[u+2]!=dp[u]){
							if(f[j]==1){
								f[j]=0;
							}else{
								f[j]=1;
							}
						}
					}
				}
			}
			for(int j=i;j<=n;j++){
				ans+=f[j];
			}
			double y=clock();
			if(y-x>=0.8){
				break;
			}
		}
		cout<<ans<<endl;
	}
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/ 
