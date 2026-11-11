#include <bits/stdc++.h>

using namespace std;

long long n, m;
long long a[500005];
long long diff[500005];
unsigned long long delta[500005];

long long sumup(int b, int e) {
    if (b == 0) {
        return diff[e];
    }
    
    return diff[e] - diff[b - 1];
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    long long c = 0;
    for (int _ = 0; _ < n; ++_) {
	cin >> a[_];
    }

    sort(&a[0], &a[n]);
    
    for (int _ = 0; _ < n; ++_) {
	c += a[_];
	diff[_] = c;
    }

    int ans = 1;
    for (int i = 0; i < n; ++i) {
	unsigned long long delta = 0;
	
	int beg = i - ans + 1;
	int end = i - 1;
	delta += (end - beg + 1) * a[i];
	delta -= sumup(beg, end);
	
        for (int j = i - ans; j >= 0; --j) {
	    delta += (a[i] - a[j]);
	    if (delta > m) {
	        break;
	    }
	    ans = max(ans, i - j + 1);
	}
    }

    cout << ans << endl;
}
