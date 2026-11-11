#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n,res = 0;
long long m,a[maxn],sum[maxn] = {0},dp[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++) cin>>a[i];
	sort(a + 1,a + n + 1);
	for(int i = 1;i <= n;i++) sum[i] = sum[i - 1] + a[i];
	int j = 1,tmp;
	for(int i = 1;i <= n;i++){
		tmp = i - j + 1;
		dp[i] = tmp * a[i] - (sum[i] - sum[j - 1]);
		while(dp[i] > m){
			dp[i] -= a[i] - a[j];
			j++,tmp--;
		}
		res = max(res,tmp);
	}
	cout<<res;
	return 0;
}