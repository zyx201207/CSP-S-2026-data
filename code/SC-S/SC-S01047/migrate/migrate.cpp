#include<bits/stdc++.h>
#define int long long
#define all(x) (x).begin(),(x).end()
using namespace std;

namespace A{
	void sol(){
		int n,d;
		cin>>n>>d;
		vector<int>a(n+1);
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int x=a[2]-a[1];
		if(d<x*2){
			cout<<"0\n";
			return;
		}
		cout<<n-3<<'\n';
	}
}

namespace M1{
	int n,d;
	void sol(){
		cin>>n>>d;
		vector<int>a(n+1);
		vector<vector<int>>dp(n+1,vector<int>(n+1,1e18)),nt(n+1,vector<int>(n+1));
		for(int i=1;i<=n;i++)	cin>>a[i];
		for(int i=1;i<=n;i++){
			int p=1;
			while(a[i+p]<=a[i]+d){
				dp[i][i+p]=1;
				p++;
			}
		}
		for(int i=1;i<=n;i++){
			dp[i][i]=0;
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(dp[i][j]>dp[i][k]+dp[k][j]){
						nt[i][j]=1;
						dp[i][j]=dp[i][k]+dp[k][j];
					}else if(dp[i][j]==dp[i][k]+dp[k][j]){
						nt[i][j]++;
					}
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(nt[i][j]==2)	ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
signed main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c=0,T=1;
	cin>>c>>T;
	if(c<=6){
		while(T--){
			M1::sol();
		}
	}
	else if(c==11 or c==12){
		while(T--){
			A::sol();
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/