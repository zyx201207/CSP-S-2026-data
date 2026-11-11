#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX >> 1;
//CSP-J 2026 RP+=INF

struct Node {
	int a, cnt;
} nd[200005];

bool cmp(Node a, Node b) {
    if(a.cnt != b.cnt) {
        return a.cnt > b.cnt;
    }
    return a.a > b.a;
}

int n, m, cnt;
long long pw2[30], sum;
bool aad[200005][30];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    pw2[0] = 1;
    for(int i = 1; i <= 30; i++) {
        pw2[i] = (pw2[i - 1] << 1);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> nd[i].a;
        sum += nd[i].a;
        for(int j = 0; j <= 29; j++) {
        	aad[i][j] = (nd[i].a & pw2[j]) >> j;
        	if(aad[i][j]) {
        		nd[i].cnt++;
			}
		}
    }
    if(sum / n == n - m - 1) {
        cout << n - m;
        return 0;
    }
    int ans = INT_MAX;
    sort(nd + 1, nd + n + 1, cmp);
    for (int i = 1; i <= m; i++) {
        ans &= nd[i].a;
    }
    cout << ans;
    return 0;
}
