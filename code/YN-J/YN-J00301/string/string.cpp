#include <bits/stdc++.h>
using namespace std;

struct node {
	long long count;
	char text;
};
node a[100000];
long long n;

string yvan = {};

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i].count >> a[i].text;
	}
//	if (n == 1) {
//		cout << "0";
//		return 0;
//	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= a[i].count; j++) {
			yvan += a[i].text;
		}
	}
//	cout << yvan;
	return 0;
}