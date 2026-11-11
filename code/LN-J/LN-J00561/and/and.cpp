#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll a[200005];
ll n2[50];
vector <int> b[35];

bool cmp(ll x1, ll x2) {return x1 > x2;}

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);

    n2[0] = 1;
    for (int i = 1; i <= 31; i++) {
        n2[i] = n2[i - 1] * 2;
    }


    for (int i = 30; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if ((a[j] / n2[i]) % 2 == 1) {
                b[i].push_back(j);
            }
        }
    }
    vector <int> ans;
    int k;
    for (int i = 30; i >= 0; i--) {
        if (b[i].size() >= m) {
            for (int j : b[i]) ans.push_back(j);
            k = i;
            break;
        }
    }
    for (int i = k - 1; i >= 0 && ans.size() > m; i--) {
        int l = 0, cnt = 0;
        for (int j : b[i]) {
            while (ans[l] != j && l < ans.size()) l++;
            if (l == ans.size()) break;
            cnt++;
        }
        if (cnt >= m) {
            vector <int> ans1;
            l = 0;
            for (int j : b[i]) {
                while (ans[l] != j && l < ans.size()) l++;
                if (l == ans.size()) break;
                ans1.push_back(j);
            }
            ans = ans1;
        }
    }
    int sum = a[ans[0]];
    for (int i = 1; i < m; i++) {
        sum &= a[ans[i]];
    }
    cout << sum << endl;
    return 0;
}
