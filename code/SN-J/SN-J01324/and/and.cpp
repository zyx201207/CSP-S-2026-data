#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, a[N], cnt[50], ans, m;
vector<int> v;
signed main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	vector<int> v;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		v.push_back(a[i]);
		for(int j = 32; j >= 0; j--){
			cnt[j] += (a[i] >> j & 1);
		}
	}
	for(int j = 32; j >= 0; j--){
		int cnt = 0;
		for(auto i : v){
			if(i >> j & 1){
				cnt++;
			}
		}
		if(cnt >= m){
//		cout << cnt << "\n";
			vector<int> nv;
			for(auto i : v){
				if(i >> j & 1) nv.push_back(i);
				
			}
			v = nv;
			ans |= 1 << j;
		}
	}
	cout << ans;
	return 0;
}
