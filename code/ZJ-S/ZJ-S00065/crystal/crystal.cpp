#include <bits/stdc++.h>
using namespace std;
const long long INF = LLONG_MAX >> 1;
//2026CSP-S RP<<=INF

struct Node {
    long long val, dlt;
} nd[500005];

bool cmp(Node a, Node b) {
    return a.val < b.val;
}

int n, ans;
long long m;
unsigned long long sum[500005];

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> nd[i].val;
    }
    sort(nd + 1, nd + n + 1, cmp);
    for (int i = 1; i <= n; i++) {
        nd[i].dlt = nd[i + 1].val - nd[i].val;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + nd[i].dlt * i;
        if(m < sum[i]) {
            cout << ans;
            return 0;
        }
    }
    return 0;
}
