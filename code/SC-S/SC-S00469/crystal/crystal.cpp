#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
long long m,a[500050],dp[500050],ans,l,r,f[500050][24],pre[500050];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2; i<=n; i++) {
		pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	l=1;
	dp[1]=1;
	long long w=m;
	f[n][0]=n;
	for(int i=n; i>=1; i--) {
		if(i==n) {
			f[i][0]=n;
		} else {
			f[i][0]=i+1;
		}
		for(int j=1; j<=20; j++) {
			f[i][j]=f[f[i][j-1]][j-1];
		}
	}
	for(int i=2; i<=n; i++) {
		if(pre[i]-pre[l]-(l-1)*(a[i]-a[l])>m) {
			for(int j=20; j>=0; j--) {
				int to=f[l][j];
				if(to<=i&&m<pre[i]-pre[to]-(to-1)*(a[i]-a[to])) {
					l=to;
				}
			}
			int to=f[l][0];
			l=to;
			dp[i]=i-l+1;
		} else {
			dp[i]=dp[i-1]+1;
			w-=dp[i-1]*(a[i]-a[i-1]);
		}
		ans=max(ans,dp[i]);
	}
	cout<<ans;
	return 0;
}