#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;

int n, ans;
long long m, mn = 1e18, mx = -1e18, a[N], pre[N];
bool ck1 = 1, ck2 = 1;

void solve1() {
	long long s = 0;
	for (int i = n - 1;i >= 1;i--) {
		s += n - i;
		if (s > m) {
			cout << n - i;
			return ;
		}
	}
	cout << n;
	return ;
}

void solve2() {
	long long s = 0;
	for (int i = n - 1;i >= 1;i--) {
		s += a[n] - a[i];
		if (s > m) {
			cout << n - i;
			return ;
		}
	}
	cout << n;
	return ;
}

int ck(int x) {
    long long s = 0;
    int id = n;
    for (int i = 1;i <= n;i++) 
    	if (a[i] > x) {
    		id = i - 1;
    		break;
		}
	for (int i = id;i >= 1;i--) {
    	s += x - a[i];
        if (s > m) return id - i;
	}
    return id;
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) {
        cin >> a[i];
        mx = max(a[i], mx);
        if (a[i] != i) ck1 = 0;
    }
    sort(a + 1, a + n + 1);
    
    long long cha = a[2] - a[1];
    for (int i = 3;i <= n;i++) 
    	if (a[i] - a[i - 1] != cha) {
    		ck2 = 0;
    		break;
		}
    
    if (ck1) solve1();
    else if (ck2) solve2();
    else {
	    for (int i = 1;i <= n;i++) {
	    	pre[i] = a[i] + pre[i - 1];
	    	mn = min(mn, (pre[i] + m) / i);
		}
	    
	    for (int i = mn;i <= mx;i++) ans = max(ans, ck(i));
	    cout << ans;
	}
	return 0;
}
