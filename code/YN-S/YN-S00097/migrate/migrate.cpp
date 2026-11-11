#include <bits/stdc++.h>
using namespace std;

long long a[2000001];

struct f {
	long long n, v;
} b[100001];

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	long long c;
	cin >> c;
	long long t;
	cin >> t;
	for (long long i = 1; i <= t; i++) {

		cin >> b[i].n >> b[i].v;
		for (int j = 1; j <= b[i].n ; j++) {
			cin >> a[i];
		}


	}





	return 0;
}