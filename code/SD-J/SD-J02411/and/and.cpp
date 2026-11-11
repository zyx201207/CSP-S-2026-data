#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n, m;
vector<int>vc;
map<int, int>mp;
int a[200010], dp[200010];
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		if(mp[a[i]] == 0){
			mp[a[i]] = 1;
			vc.push_back(a[i]);
		}
	}
	sort(vc.begin(), vc.end());
	int len = vc.size();
	int ans = vc[len - 1];
	int r = len - 1;
	for(int i = 1; i <= m; i++){
		ans = ans & vc[r];
		r--;
	}
	cout << ans;
}
