#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
long long n, m, cei;

vector<ll> num;

int main() {
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout);
	cin >> n >> m;
	vector<ll> a(n + 1, 0);
	vector<ll> b(n + 1, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	b[0] = a[0];
	for (int i = 1; i < n; i++) {
		b[i] = a[i] + b[i - 1];
	}
	/*
	for(int i=0;i<n;i++){
		b[i]-=b[i-1];
	}
	*/
	for (int i = 1; i < m; i++) {
		ll sum = 0;
		ll p = m;
		while (p--) {
			a[i] += 1;
			b[0] = a[0];
			b[i] = a[i] + b[i - 1];
			b[i + 1] = b[i] + a[i + 1];
			if (b[i + 1] == 2 * b[i]) {
				sum++;
			}
		}
		num.push_back(sum);
	}
	sort(num.begin(), num.end(), greater<int>());
	cout << num[0];

	return 0;
}