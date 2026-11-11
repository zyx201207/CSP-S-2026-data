#include <bits/stdc++.h>
using namespace std;
struct e{
    string ss;
    long long x;
}l[200005];
string to_bin(long long a) {
    string s = "";
    while(a) {
        s = (a%2 ? '1' : '0') + s;
        a /= 2;
    }
    while(s.size()< 30) s = '0' + s;
    return s;
}
bool cmp(e a, e b) {
    for (int i = 0; i < 30; i++) {
        if (a.ss[i] == '1' && b.ss[i] == '0') return 0;
        if (b.ss[i] == '1' && a.ss[i] == '0') return 1;
    }
    return 1;
}

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n, m, a;
    cin >> n >> m;
    for (int i = 1;i <= n; i++) {
        cin >> a;
        l[i].x = a;
        l[i].ss = to_bin(a);
    }
    sort(l+1, l+n+1,cmp);
    int num[30] = {};
    for (int i = 0; i < 30; i++) {
        for (int j = 1; j <= n; j++) {
            if (l[j].ss[i] == '1') num[i]++;
        }
    }
    queue<e> q;
    for (int i= 1; i <= n; i++) q.push(l[i]);
    for (int i = 0; i < 30; i++) {
        if (num[i] >= m) {
            for (int j = 1; j <= q.size(); j++) {
                if (q.size() == m) break;
                if (q.front().ss[i] == '0') q.pop();
                else {
                    e pp = q.front();
                    q.pop();
                    q.push(pp);
                }
            }
            }
            if (q.size() == m) break;
        }

    long long ans = q.front().x;
    for (int i = 1; i <= m; i++) {
        ans &= q.front().x;
        q.pop();
    }
    cout << ans;
    return 0;
}
