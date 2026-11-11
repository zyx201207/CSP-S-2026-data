#include <bits/stdc++.h>
using namespace std;
//const long long N=
long long n,m;
vector<long long> a;
vector<long long> dp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	a.resize(n+1);
	dp.resize(n+1);
	int sum=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+i-1;
	}

	for(int i=1;i<=n;i++){
		if(dp[i]>sum){
			cout<<i-1;
			return 0;
		}
	}
	return 0;
}
