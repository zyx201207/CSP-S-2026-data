//22.01
#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, ans = 0, cnt = 0, fck = 0, j = 0;
	cin >> n >> m;
	vector<int> a(n);
	vector<int> ak(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	for(int i = 0; i < n; i ++) {
		for(int j = i - 1; j >= 0; j --) {
			if(ans + (a[i] - a[j]) > m) {
				break;
			}
			ans += a[i] - a[j];
			cnt ++;
		}
		for(int k = i; k < n; k ++) {
			if(a[i] == a[k]) cnt ++;
		}
		
		ak[fck] = cnt;
		ans = 0;
		cnt = 0;
		fck ++;
	}
	sort(ak.begin(), ak.end());
	cout << ak[n - 1];
}

