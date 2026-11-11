#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],ans;
long long dp[2005][2005];
map<int,int> mp;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> n >> m >> a[1];
	long long sum=a[1],mx=a[1];
	for(int i=2;i<=n;i++){
		cin >> a[i];
		sum&=a[i];
		mx=max(mx,a[i]);
		mp[a[i]]++;
	}
	if(m==n)cout << sum;
	else if(m==n-1){
		for(int i=1;i<=n;i++){
			if(mp[a[i]]==1)ans=max(ans,sum^a[i]);
		}
		cout << ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout << ans;
	}
	else if(n<=2000){
		memset(dp,0,sizeof dp);
		for(int i=1;i<=n;i++){
			dp[i][1]=max(dp[i-1][1],a[i]);
			for(int j=2;j<=min(i,m);j++){
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-1]&a[i]);
			}
		}
		cout << dp[n][m];
	}
	else{
		sort(a+1,a+n+1,cmp);
		int ans=a[n];
		for(int i=1;i<m;i++)ans=ans&a[n-i];
		cout << ans;
	}
	return 0;
}//60
//I am died.
//Can I get the first prize?
// I do not know.