#include <bits/stdc++.h>
#define ll long long
using namespace std;
const ll N = 5e5+5;
ll n, m, arr[N], mymax = -1;

ll check(ll a) {
	ll sum = 1, s = m;
	for (int i = a - 1; i >= 1; i--) {
		if (s < arr[a] - arr[i])
			break;
		s -= (arr[a] - arr[i]);
		sum++;
	}
	return sum;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	sort(arr + 1, arr + n + 1);
	ll l = 1, r = n;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll sum = check(mid);
		mymax = max(mymax, sum);
		if (sum == mid)
			l = mid + 1;
		else
			r = mid - 1;
	}
	cout << mymax;
	return 0;
}
