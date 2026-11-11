#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m;
int a[N],dp[N][30];
ll maxx=-0x3f3f3f3f;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		dp[i][0]=a[i];
	}
	for(int j=1;j<=log2(n);j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			dp[i][j]=dp[i][j-1]&dp[i+(1<<(j-1))][j-1];
		}
	}
	for(int i=1;i<=n-m+1;i++){
		int k=log2(m);
		ll ans=dp[i][k-1]&dp[i+(1<<(k-1))][k-1];
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}

