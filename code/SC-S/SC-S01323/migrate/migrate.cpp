#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
const int N=2e3+5;
int c,t,n,d,x[N],dp[N][N];
void solve(){
	cin>>n>>d;
	int j=1,ans=0,q=1;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		int sum=x[i]-d;
		while(x[j]<sum)j++;
		if(j==i)q=j;
		for(int k=q;k<j;k++){
			dp[k][i]=dp[k][j]+1;
			if(dp[k][j]==dp[k][j+1]&&dp[k][j+1]!=dp[k][j+2])ans++;
		}
		for(int k=j;k<i;k++)dp[k][i]=1;
		dp[i][i]=0;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}