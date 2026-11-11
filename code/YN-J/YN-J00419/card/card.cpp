#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500010];
int tong[300010];
int chu[500010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		chu[i] = a[i];
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			for (int k = i; k < j; k++) {
				if (chu[j] == chu[k]) {
					//cout << chu[j] << " ";
					for (int l = k; l < j; l++)
						chu[l] = 0;
				}
			}
			//cout << endl;
		}
		for (int j = i; j <= n; j++) {
			if (chu[j] != 0)
				//cout << chu[j] << " ";
				tong[chu[j]]++;
			chu[j] = a[j];
		}
		//cout << endl;
	}
	for (int i = 1; i <= m; i++) {
		cout << tong[i] << " ";
	}
	return 0;
}