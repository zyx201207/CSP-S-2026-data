#include <bits/stdc++.h>
#include <vector>
#include <cstdio>
#define OI ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
int n, m;
int a[500005];
vector <int> v;
long long t[500005];

void cal(int i) {
//	cout << i << ":";
	v.clear();
	for (; i <= n; ++i) {
		bool flag = 0;
		vector<int>::iterator it;
		it = v.begin();
		for (it; it < v.end(); ++it) {
			if (*it == a[i]) {
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			v.erase(it, v.end());
		v.push_back(a[i]);
	}
	vector<int>::iterator it;
	it = v.begin();
	for (it; it < v.end(); ++it) {
		t[*it]++;
//		cout << *it << endl;
	}
//	cout << "\n";
}

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	OI
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	int k = 1;
	while (k <= n) {
		cal(k);
		k++;
	}
	for (int i = 1; i <= m; ++i) {
		cout << t[i] << " ";
	}



	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/