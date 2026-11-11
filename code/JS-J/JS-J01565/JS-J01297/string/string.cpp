#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, ans;
int a[200005];
char c[200005];
struct node {
    int cha, sum;
} ;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
    }
    queue<node>q1, q2;
    int i = 1, j = n;
    while (i <= j) {
        if (q1.size()) {
            if (q1.front().cha == c[i]) {
                q1.front().sum += a[i];
                i++;
            }
        }
        else q1.push({c[i], a[i]}), i++;
        if (q2.size()) {
            if (q2.front().cha == c[j]) {
                q2.front().sum += a[j];
                j--;
            }
        }
        else q2.push({c[j], a[j]}), j--;
        node u = q1.front(), v = q2.front();
        q1.pop(), q2.pop();
        if (u.sum > v.sum) q1.push({u.cha, u.sum - v.sum}), ans += v.sum * (u.cha != v.cha);
        else if (u.sum < v.sum) q2.push({v.cha, v.sum - u.sum}), ans += u.sum * (u.cha != v.cha);
        else ans += u.sum * (u.cha != v.cha);
    }
    while (q1.size() && q2.size()) {
        node u = q1.front(), v = q2.front();
        q1.pop(), q2.pop();
        if (u.sum > v.sum) q1.push({u.cha, u.sum - v.sum}), ans += v.sum * (u.cha != v.cha);
        else if (u.sum < v.sum) q2.push({v.cha, v.sum - u.sum}), ans += u.sum * (u.cha != v.cha);
        else ans += u.sum * (u.cha != v.cha);
    }
    cout << ans;
}