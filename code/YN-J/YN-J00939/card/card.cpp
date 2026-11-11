#include <bits/stdc++.h>
using namespace std;

vector<int> b;

bool inc(int k) {
	bool flag = 0;
	for (auto it = b.begin(); it <= b.end(); it++) {
		if (k == *it)
			flag = 1;
	}
	return flag;
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	return 0;
}
