#include <iostream>
#include <vector>
#include <cstdio>
#include <climits>
#include <algorithm>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,k;
	cin>>n>>k;
	vector<int> dp(k+1);
	vector<int> v(n);
	for (auto &i : v) cin>>i;
	sort(v.begin(),v.end());
	dp[0] = 0xFFFFFFFF;
	for (int i=1;i<=n;i++){
		int a;
		//cin>>a
		a = v[i-1];
		for (int j=k;j>=1;j--){
			dp[j] = max(dp[j-1]&a,dp[j]);
			//cerr<<"a:"<<a<<" | j:"<<j<<" "<<(dp[j-1]&a)<<" "<<dp[j]<<endl;
		}
	}
	cout<<dp[k]<<endl;
}
