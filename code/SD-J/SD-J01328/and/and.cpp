#include<bits/stdc++.h>
using namespace std;
int a[100010],dp[100010];
int n,m;
int main() {
	freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
	cin>>n>>m;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		dp[i]=a[i]&a[i-1];
	}
	for(int i=m; i<=n; i++) {
		dp[i]=max(dp[i],dp[i]&a[i]);
	}
	int anss=0;
	for(int i=1; i<=n; i++)anss=max(anss,dp[i]);
	cout<<anss;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
