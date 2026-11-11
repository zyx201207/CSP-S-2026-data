#include<iostream>
#include<algorithm>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
ll cyt[N];
ll n, m;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> cyt[i];
	}
	sort(cyt + 1, cyt + n + 1);
	
	ll cost = 0;
	for (int i = 2; i <= n; i ++) {
		cost += (cyt[i] - cyt[i - 1]) * (i - 1);
		if(cost > m) {
			cout << i - 1<< endl;
			return 0;
		}
	}
	
	cout << n << endl;
	return 0;
}