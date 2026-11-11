#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, cnt;
struct node{
    int a; char c;
} b[200005];
vector<char> ve;
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    ve.push_back('#');
    for (int i = 1; i <= n; i++) {
        cin >> b[i].a >> b[i].c;
        for (int j = 1; j <= b[i].a; j++) ve.push_back(b[i].c);
    }
    int sz = ve.size() - 1, ans = 0;
    for (int i = 1; i <= sz / 2; i++) {
        if (ve[i] != ve[sz - i + 1]) ans++;
    }
    cout << ans;
    return 0;
}
