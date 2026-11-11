#include<iostream>
#include<algorithm>
using namespace std;
long long a[200005];
bool f[200005];
long long dp[200005];
int n,m;
long long ans;
void dfs(int c,long long sum) {
	if(c==m+1)
	{
		ans=max(ans,sum);
		return;
	}
	for(int i=1; i<=n; i++){
		if(f[i]==0&&(a[i]&sum)>dp[i]) {
			f[i]=1;
			dp[i]=a[i]&sum;
			dfs(c+1,sum&a[i]);
			f[i]=0;
		}
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=1; i<=n; i++) {
		if(f[i]==0&&a[i]>dp[i]) {
			f[i]=1;
			dp[i]=a[i];
			dfs(2,a[i]);
			f[i]=0;
		}
	}
	cout<<ans;
	return 0;
}
