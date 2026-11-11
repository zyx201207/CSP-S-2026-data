#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int n, m;
long long a[N];
int g[N][40];
long long ans;

void work(int i) {
    long long k = a[i];
    int j = 0;
    while(k) {
        g[i][j] = k % 2;
        k /= 2;
        j++;
    }
    return ;
}
int check(int k, int j) {
    int cnt = 0;
    long long sum = LLONG_MAX;
    for(int i = 1; i <= n; i++) {
        if(g[i][j] && (sum & a[i]) >= k) {
            cnt++;
            sum = sum & a[i];
        }
        if(sum < k) {
            return false;
        }
    }
    return (cnt < m ? false : true);
}

int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        work(i);
	}
	for(int i = 31; i >= 0; i--) {
        if(check(ans + (1 << i), i)) {
            ans += (1 << i);
        }
	}
	cout << ans << endl;
	return 0;
}
