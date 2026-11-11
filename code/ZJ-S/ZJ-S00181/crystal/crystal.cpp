#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
ll m;
ll a[500005];
ll f[500005];
int lg2[500005];
ll st[500005][30];

ll get_max(int l, int r) {
	int len = r - l + 1;
	int f = lg2[len];
	ll f1 = st[l][f];
	ll f2 = st[r - (1 << f) + 1][f];
	return max(f1, f2);
}

bool check(int l, int r) {
	ll sum = f[r] - f[l - 1];
	ll want = get_max(l, r) * (r - l + 1);
	if (llabs(sum - want) <= m) {
		return true;
	} else {
		return false;
	}
}

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    for (int i = 1; i <= n; i++) {
    	st[i][0] = a[i];
	}
    
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
    	f[i] = f[i - 1] + a[i];
	}

	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j + (1 << i) - 1 <= n; j++) {
			st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
		}
	}
	
	lg2[2] = 1;
	for (int i = 2; i <= n; i++) {
		lg2[i] = lg2[i / 2] + 1;
	}

    sort(a + 1, a + n + 1);

	int res = 1;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n;
        int ans = l;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) {
				l = mid + 1;
				ans = mid; 
            } else {
            	r = mid - 1;
            }
        }
		res = max(res, ans - i + 1);
    }
    cout << res << '\n';
}
