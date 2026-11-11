/*#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int a[500010], cntm[500010], appeared[500010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	for (int i=1; i<=n; i++) {
		memset(appeared, 0, sizeof(appeared));
		for (int j=i; j<=n; j++) {
			if (appeared[a[j]]) {
				for (int k=j-1; a[k]!=a[j]; k--) {
					appeared[a[k]]--;
				}
			}
			else {
				appeared[a[j]]++;
			}
		}
		for (int j=1; j<=m; j++) {
			if (appeared[j])	cntm[j]++;
		}
	}
	for (int i=1; i<=m; i++) {
		cout << cntm[i] << " ";
	}
	return 0;
	
}*/
#include <iostream>
#include <cstdio>
using namespace std;
int a[500010];
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	cin >> a[1];
	for (int i=2; i<=n; i++) {
		cin >> a[i];
		if (a[i]!=a[i-1])	cout << i-1 << " ";
	}
	cout << n;
	return 0;
}
