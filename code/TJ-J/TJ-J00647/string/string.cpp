#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n = 0;
int a[N];
char c[N];
long long ans;

int main() {
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        //cout << a[i] << " " << c[i] << endl;
	}
	for(int i = 1, j = n; i <= j;) {
        if(a[i] <= a[j]) {
            if(c[i] != c[j]) {
                ans += a[i];
            }
            a[j] -= a[i];
            j -= (a[j] == 0 ? 1 : 0);
            a[i] = 0;
            i++;
        }
        if(a[i] > a[j]) {
            if(c[i] != c[j]) {
                ans += a[j];
            }
            a[i] -= a[j];
            a[j] = 0;
            j--;
        }
	}
	cout << ans << endl;
	return 0;
}
