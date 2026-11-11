#include <bits/stdc++.h>

using namespace std;

int x;
bool Special = true;

int main() {
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n;
	long long m;
	cin >> n >> m;
	vector<long long> v(n,0);
	for(int i = 0;i < n;i++) {
		cin >> v[i];
	}
	sort(v.begin(),v.end());
	if(n >= 2) {
		x = v[1] - v[0];
		for(int i = 2;i < n;i++) {
			if(v[i]-v[i-1] != x) {
				Special = false;
				break;
			}
		}
	}
//	if(Special) {
//		int ans = 0;
//		for(int i = 0;m - i*x >= 0;i++) {
//			ans++;
//			m -= i*x;
//		}
//		cout << min(ans,n);
//		return 0;
//	}
	if(Special) {
		int a = 0;
		for(int i = 1;i <= n;i++) {
			a += i * x;
			if(a > m) {
				cout << i <<endl;
				return 0;
			}
		}
		cout << n << endl;
		return 0;
	}
	long long ans = -2147483647;
	for(int i = 0;i < n;i++) {
		long long less = m;
		long long choice = 1;
		for(int j = i-1;j >= 0;j--) {
			if(v[i] - v[j] <= less) {
				less -= v[i] - v[j];
				choice++;
			}
		}
		ans = max(ans,choice);
	}
	cout << ans;
	return 0;
}
