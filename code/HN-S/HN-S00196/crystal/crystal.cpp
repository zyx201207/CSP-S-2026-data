#include<bits/stdc++.h>
using namespace std;
long long n,m,maxn=-1;
vector<long long> a;
vector<long long> dp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	a=vector<long long> (n+1,0);
	dp=vector<long long> (n+1,0);
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	dp[0]=0;
	for (int i=1;i<=n;i++){
		dp[i]=dp[i-1]+(i-1)*(a[i]-a[i-1]);
		int ans=0;
		for (int j=1;j<=i;j++){
			ans+=a[i]-a[j];
			if (dp[i]-ans<=m) maxn=max((i-j)*1LL,maxn);
		}
	}
	cout<<maxn;
	return 0;
} 
