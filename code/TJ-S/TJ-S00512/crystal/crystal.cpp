#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
long long n, m;
long long a[N];

int check(int k) {
    long long sum = 0, minv = 0;
    for(int i = 1; i <= k; i++) {
        sum += a[k] - a[i];
    }
    minv = sum;
    for(int i = 2; i <= n - k + 1; i++) {
        sum -= (a[i - 1 + k - 1] - a[i]);
        sum += (a[i + k - 1] - a[i - 1 + k - 1]) * (k - 1);
        minv = min(minv, sum);
    }
    return (minv <= m ? 1 : 0);
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
        cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0;
	while(l <= r) {
        int mid = (l + r) / 2;
        if(check(mid)) {
            ans = mid;
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
	}
	printf("%d", ans);
	return 0;
}
