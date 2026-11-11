#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 100010;
ll n;
string c1, s1, c2, s2;
bool t1, t2, t3, t4;

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	t1 = false;
	t2 = false;
	t3 = false;
	t4 = false;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1 == c2) {
		t1 = true;
	} else {
		cout << "0000";
		return 0;
	}
	if (s1[0] == s2[0] && s1[1] == s2[1]) {
		t2 = true;
	} else {
		cout << "1000";
		return 0;
	}
	ll c1 = s1[2] - 'A', c2 = s2[2] - 'A';
	if (c1 <= 2 && c2 <= 2 || c1 >= 3 && c2 >= 3) {
		t3 = true;
	} else {
		cout << "1100";
		return 0;
	}
	if (c1 < c2)
		swap(c1, c2);
	if ((c1 - c2) == 1 && c1 != 3) {
		t4 = true;
	} else {
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
