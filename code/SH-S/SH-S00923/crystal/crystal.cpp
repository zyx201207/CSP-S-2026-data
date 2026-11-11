#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long ans, cnt = 2, cur, x;
map <long long, int> mp;
priority_queue <long long, vector <long long>, greater <long long>> gp;
vector <long long> a;
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    a.push_back(0);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        mp[x]++;
        if (mp[x] == 1) {
            gp.push(x);
            a.push_back(x);
        }
    }
    ans = mp[gp.top()];
    gp.pop();
    sort(a.begin() + 1, a.end());
    for (; !gp.empty(); ) {
        long long m1 = m;
        cur = mp[gp.top()];
        for (int j = cnt - 1; j >= 1 && m1 > gp.top() - a[j]; j--) {
            long long k = mp[a[j]] * (gp.top() - a[j]);
            if (m1 >= k) {
                m1 -= k;
                cur += mp[a[j]];
            }
            else {
                while (m1 > gp.top() - a[j]) {
                    m1 -= gp.top() - a[j];
                    cur++;
                }
            }
        }
        ans = max(ans, cur);
        gp.pop();
        cnt++;
    }
    cout << ans;
    return 0;
}
