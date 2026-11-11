#include <bits/stdc++.h>
using namespace std;

int a[100000] = {};
int b1(int a, int c);

int main() {
	//freopen("hub.in", "r", stdin);
	//freopen("hub.out", "w", stdout);
	int  c, n, d, t;
	cin >> c >> t >> n >> d ;
	int sum = 0;
	int cnt = 0;
	for (int i = 1; i <= d; i++) {
		cin >> a[i];
		int s1 = a[i];
		for (int j = 1; j <= d; j++) {
			int s2 = a[j];
			cin >> a[j];
			if (s1 == s2)
				sum++;
			if ( sum == 2)
				cnt++;
		}
	}
	cout << cnt << endl;

	return 0;
}