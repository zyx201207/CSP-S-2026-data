#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 5e5 + 10;
int n;
ll m;
ll a[maxn];
ll qcha[maxn];
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		qcha[i] = a[i] - a[i-1];
	}
	bool flag = true;
	for(int i=3; i<=n; i++) {
		if(qcha[i] != qcha[i-1]) {
			flag = false;
		}
	}
	sort(a+1, a+n+1);
	if(flag == true) {
		int he = 0;
		int i;
		for(i=1; i<n; i++) {
			he += i;
			if(m < he * (a[2] - a[1])) {
				break;
			}
		}
		cout << i;
		return 0;
	}
	cout << n/2;
	return 0;
}
