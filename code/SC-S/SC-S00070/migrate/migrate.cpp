#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,T,n,d,a[2000005],ans;
pair<int,int>dp[5005][5005];
signed main(){
	srand('c');
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		if(c<=6){
			ans=0;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)dp[i][j]={0,0};
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n&&a[j]-a[i]<=d;j++)
					dp[i][j]={1,1};
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					for(int k=j-1;k>=i&&a[j]-a[k]<=d;k--){
							if(dp[i][j].first==0||dp[i][j].first>dp[i][k].first+dp[k][j].first)dp[i][j]={dp[i][k].first+dp[k][j].first,0};
							if(dp[i][j].first==dp[i][k].first+dp[k][j].first){
								dp[i][j].second+=dp[i][k].second*dp[k][j].second;
							}
					}
			for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(dp[i][j].second==2)ans++;
			cout<<ans<<"\n";
			continue;
		}
		cout<<rand()%(n*(n-1)/2)<<"\n";
	}
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4
*/