#include <bits/stdc++.h>
using namespace std;

long long a, b;
bool is_b = true;
bool is_a = true;
long long step, ans, net, sum, ll;

long long lit[100000000];
int melit[100000000];
bool use [100000000];
int relit[100000000];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> a >> b;

	for (int i = 1; i <= a; i++) {
		cin >> lit[i];
	}
	sort(lit + 1, lit + 1 + a);
	melit[1] = lit[1];
	for (int i = 2; i <= a; i++) {
		if (is_a == true && lit[i] != 1) {
			is_a = false;
		}
		melit[i] = lit[i] - lit[i - 1];
		if (is_b == true && melit[i - 1] != melit[i]) {
			is_b = false;
		}
	}
//	cout << is_a << " " << is_b << endl;
	if (is_a) {
		net = 2;
		use[1] = true;
		sum = 1;
		for (int i = 1; i <= a; i *= 2) {
			use[i] = true;
			step = i;
			ll = i;
			ans++;
		}
		while (step <= a && sum <= b) {
			if (sum + net > b) {
				break;
			}
			sum += net;
			ans++;
			net++;
			step++;
			use[step] = true;
		}
		while (ll > 1 && sum <= b) {
			if (use[ll - 1] != true) {
				if (sum - 1 + net > b) {
					break;
				}
				sum += net - 1;
				net++;
				ans++;
				ll--;
				use[ll] = true;
			} else {
				ll--;
				net++;
			}
		}
		cout << ans << endl;
		return 0;
	} else if (is_b) {
		net = melit[2];
		use[1] = true;
		sum = 1;
		for (int i = 1; i <= a; i *= 2) {
			use[i] = true;
			step = i;
			ll = i;
			ans++;
		}
		while (step <= a && sum <= b) {
			if (sum + net > b) {
				break;
			}
			sum += net;
			ans++;
			net += melit[2];
			step++;
			use[step] = true;
		}
		while (ll > 1 && sum <= b) {
			if (use[ll - 1] != true) {
				if (sum - melit[2] + net > b) {
					break;
				}
				sum += net - melit[2];
				net += melit[2];
				ans++;
				ll--;
				use[ll] = true;
			} else {
				ll--;
				net += melit[2];
			}
		}
		cout << ans << endl;
		return 0;
	} else {
		int m, l = 0, j = 1;
		m = melit[1];
		for (int i = 1; i <= a; i++) {
			if (m == relit[i]) {
				l++;
			} else {
				relit[j] = l;
				l = 0;
				j++;
			}
		}
	}
	cout << b << endl;

//	for (int i = 1; i <= a; i++) {
//		cout << melit[i] << " ";
//	}
//	cout << endl;
//	for (int i = 1; i <= a; i++) {
//		cout << relit[i] << " ";
//	}

	return 0;
}
