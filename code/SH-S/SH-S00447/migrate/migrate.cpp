#include<bits/stdc++.h>
using namespace std;
#define int long long
pair<int,int> dp[5010][5010];
int a[50010];
int len,val,ans,m,l;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	queue<int> q;
	int t,n,d;
	cin>>t>>t;
	for(int qq=1;qq<=t;++qq){
		cin>>n>>d;int ans=0;
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				dp[i][j].first=dp[i][j].second=0;
			}
		}
		dp[1][1]={0,1};
		for(int i=2;i<=n;++i){
			int f=a[i]-d;
			int p=lower_bound(a+1,a+n+1,f)-a;
			for(int j=p;j<=i;++j){
				dp[j][i].first=dp[j][i].second=1;
			}
			for(int j=1;j<p;++j){
				dp[j][i].first=1e9;
				for(int k=p;k<i;++k){
					dp[j][i].first=min(dp[j][i].first,dp[j][k].first);
				}
				for(int k=p;k<i;++k){
					if(dp[j][k].first==dp[j][i].first){
						dp[j][i].second+=dp[j][k].second;
					}
				}
				dp[j][i].first++;
			}
		//	cout<<dp[i].first<<' '<<dp[i].second<<'\n';
		}
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				if(dp[i][j].second==2){
				//	cout<<dp[1][4].second<<endl;
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
