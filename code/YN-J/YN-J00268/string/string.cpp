#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

struct node {
	long long num;
	char c;
} e[N];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long n;
	cin >> n;
	for (long long i = 1; i <= n; i++) {
		cin >> e[i].num >> e[i].c;
	}
	long long fro = 1, en = n;
	long long tot = 0;
	while (fro < en) {
		long long m = min(e[fro].num, e[en].num) ;
		e[fro].num -= m;
		e[en].num -= m;
		if (e[fro].c != e[en].c) {
			tot += m;
		}
		if (e[fro].num == 0) {
			fro++;
		}
		if (e[en].num == 0) {
			en--;
		}
	}
	cout << tot;
	return 0;
}
