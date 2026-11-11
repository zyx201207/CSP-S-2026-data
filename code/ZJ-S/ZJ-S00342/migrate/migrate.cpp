#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e6+5;
int test_num,t,n,nxt[N],cnt[N],dp[N];
ll a[N],d;
void slv1(){
	ll ans = 0;
	for (int i = 1;i <= n;++ i){
		for (int j = 1;j <= n;++ j) cnt[j] = 0,dp[j] = 1e9;
		dp[i] = 0;
		cnt[i] = 1;
		for (int j = i;j < n;++ j){
			for (int k = j + 1;k <= j + nxt[j];++ k){
				if (dp[k] > dp[j] + 1){
					dp[k] = dp[j] + 1;
					cnt[k] = cnt[j];
				}
				else if (dp[k] == dp[j] + 1) cnt[k] += cnt[j];
			}
		}
		for (int j = 1;j <= n;++ j) ans += cnt[j] == 2;
	}
	cout<<ans<<'\n';
}
void slv2(){
	cout<<"0\n";
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>test_num>>t;
	while (t --){
		cin>>n>>d;
		for (int i = 1;i <= n;++ i){
			cin>>a[i];
		}
		int p = 1;
		for (int i = 1;i <= n;++ i){ // O(n)
			ll x = a[i] + d;
			while (p < n && a[p + 1] <= x) p ++;
			nxt[i] = p - i;
		}
		if (n <= 5e3) slv1();
		else slv2();
	}
	return 0;
}