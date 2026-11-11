#include <bits/stdc++.h>
using namespace std;

int n, m, sum;
int a[500010];
int tj[500010];
int zz[500010];

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

	cin >> n >> m;
	
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		zz[i] = -1;
	}
	
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		sum = 0;
		for (int i = 1; i <= n; i++) {
			zz[i] = -1;
		}
		for (int j = i; j <= n; j++) {
			zz[sum] = a[j];
			sum++;
		}
		for (int i = 1; i <= sum; i++) {
			if (zz[i] != -1) {
				tj[zz[i]]++;
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		cout << tj[i] << " ";
	}
	
    return 0;
}

