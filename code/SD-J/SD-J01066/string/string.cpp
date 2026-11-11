#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200003];
char c[200003];
ll cnt;
int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> a[i] >> c[i];
	}
	int i = 1, j = n;
	while(i <= j) {
		if(i == j && !a[i]) break;
		if(c[i] == c[j]) {
			if(a[i] > a[j]) {
				a[i] -= a[j];
				j--;
			} else if(a[i] == a[j]) {
				a[i] = a[j] = 0;
				i++, j--;
			} else {
				a[j] -= a[i];
				i++;
			}
		} else {
			if(a[i] > a[j]) {
				cnt += a[j];
				a[i] -= a[j];
				j--;
			} else if(a[i] == a[j]) {
				cnt += a[j];
				a[i] = a[j] = 0;
				i++, j--;
			} else {
				cnt += a[i];
				a[j] -= a[i];
				i++;
			}
		}
	}
	cout << cnt;
	return 0;
}
