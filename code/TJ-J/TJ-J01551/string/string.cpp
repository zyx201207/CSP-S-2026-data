#include <bits/stdc++.h>
using namespace std;
//string s="";
const int N = 2e5 + 5;
int a[N];
char b[N];
int c[N];
char d[N];
long long cnt = 0, sum = 0;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	//string s = "";
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> b[i];
		//cout << b[i] << '\n';
		cnt += a[i];
	}

	int ix = 1;
	//stack<pair<char, int> > st;
	int i = 1;
	for (; i <= n; i++) {
		sum += a[i];
		//cout << sum;
		if (sum <= cnt / 2) {
			//cout << 1;
			c[ix] = a[i];
			d[ix] = b[i];
			ix++;
			if (sum == cnt / 2) {
				i++;
				if (cnt % 2 == 1)
					a[i ]--;
				break;
			}
		} else {
			//cout << 3;
			if (cnt % 2 == 0) {
				c[ix] = a[i] - (sum - cnt / 2);
				d[ix] = b[i];
				ix++;
				//st.push({b[i], a[i] - (sum - cnt / 2)});
				a[i] = sum - cnt / 2;
			} else {
				c[ix] = a[i] - (sum - cnt / 2);
				d[ix] = b[i];
				ix++;
				//st.push({b[i], a[i] - (sum - cnt / 2)});
				a[i] = sum - cnt / 2;
				a[i]--;
				if (a[i] - 1 == 0) {
					i++;
				}

			}
			i--;
			break;
		}

	}
	long long ans = 0;
	for (; i <= n; i++) {

		char ca = d[ix - 1];
		int p = c[ix - 1];
		//cout << ca;
		if (ca == b[i]) {
			//cout << 1;
			if (a[i] == p) {
				ix--;
			} else if (a[i] > p) {
				ix--;
				a[i] -= p;

				i--;
			} else {
				ix--;
				p -= a[i];
				c[ix] = p;
				d[ix] = ca;
				ix++;
			}
		} else {
			//cout << 1;
			if (a[i] == p) {

				ix--;
				ans += p;
			} else if (a[i] > p) {
				//cout << 2;
				ix--;
				a[i] -= p;
				ans += p;
				i--;
			} else {
				//cout << 3;
				ix--;
				p -= a[i];
				ans += a[i];
				c[ix] = p;
				d[ix] = ca;
				ix++;
			}
		}
	}

	cout << ans;
//xym
	return 0;
}