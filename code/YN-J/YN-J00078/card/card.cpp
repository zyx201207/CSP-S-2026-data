#include <iostream>
#include <vector>
using namespace std;
long long n, m;

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);

	cin >> n >> m;
	vector<long long> ans(m + 1);
	vector<long long> a(n + 1);
	vector<long long> b(m + 1);

	for (long long i = 1; i <= n; i++) {

		b[i] = 0;
		cin >> a[i];
	}

	long long l = 1;

	for (long long i = 1; i <= n; i++) {

		for (long long kk = 1; kk <= m; kk++) {

			b[kk] = 0;
		}

		l = i;

		for (long long j = i; j <= n; j++) {

			b[a[j]]++;

			if (b[a[j]] == 2) {
				l = j;
			}
		}


		for (long long k = l; k <= n; k++) {

			ans[a[k]]++;
		}
	}


	for (long long i = 1; i <= m; i++) {

		cout << ans[i] << " ";
	}

	return 0;
}