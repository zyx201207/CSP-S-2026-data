#include <bits/stdc++.h>
using namespace std;
int zi[1000];
int a[100000];

string zhuan(int b) {
	string s;
	stack<char>zhan;
	while (b > 0) {
		zhan.push(b % 2);
		b = b / 2;
	}
	for (int i = 0; i < zhan.size(); i++) {
		s.push_back(zhan.top());
		zhan.pop();
	}
	return s;
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	vector<string>q;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		q.push_back(zhuan(a[i]));
	}

}