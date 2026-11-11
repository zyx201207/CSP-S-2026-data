#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 1;

struct Node {
	int bnum;
	priority_queue<int> has;
	bool operator> (const Node& other) const {
		if (has.size() != other.has.size())
			return bnum > other.bnum;
		return has.size() > other.has.size();
	}
}has_bits[MAXN];

int a[MAXN];
size_t maxbit;
string twosys_a[MAXN];

string get_twosys(int num) {
	string res = "";
	while(num > 0) {
		res += (num & 1 == 1 ? '1' : '0');
		num >>= 1;
	}
	maxbit = max(maxbit, res.size());
	reverse(res.begin(), res.end());
	res = "000000000000000000000000000000" + res;
	res = res.substr(res.size() - 30, 30);
	return res;
} 

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> a[i];
		twosys_a[i] = get_twosys(a[i]);
	}
	for (int i = 30 - maxbit;i < 30;i++) {
		for (int j = 1;j <= n;j++) {
			if (twosys_a[j][i] == '1') {
				has_bits[30 - i].bnum++;
				has_bits[30 - i].has.push(j);
			}
		}
	}
	sort(has_bits + 1, has_bits + maxbit + 1, greater<Node>());
	long long ans = -1;
	for (size_t i = 1;i <= maxbit && m > 0;i++) {
		while (has_bits[i].has.size() > 0 && m > 0) {
			if (ans == -1) ans = a[has_bits[i].has.top()];
			else ans &= a[has_bits[i].has.top()];
			has_bits[i].has.pop();
			m--;
		}
	}
	cout << ans;
	return 0;
}
