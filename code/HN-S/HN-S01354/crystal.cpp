#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll a[N], pre[N], sum[N];
int main(){
	//freopen("crystal.in", "r", stdin);
	//freopen("crystal.out", "w", stdout);
	int n;
	ll m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for(int i = 2; i <= n; i++){
		pre[i - 1] = a[i] - a[i - 1];
	}
	sum[0] = 0;
	for(int i = 1; i <= n - 1; i++){
	      	 sum[i] = sum[i - 1] + pre[i];
	}
	int ans = 0;
	for(int i = 1; i <= n - 1; i++){
		if(sum[i] <= m){
		    ans = i + 1;
		}
	}
	cout << ans;
	return 0;
}
