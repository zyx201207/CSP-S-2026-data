#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db cerr<<"fff"<<'\n';
#define int unsigned int
signed main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> ans(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        vector<int> f(m,-1);
        vector<int> fdsa;
        for (int j = i; j < n; j++) {
            if (f[a[j]-1] != -1) {
                a.erase(a.begin()+f[a[j]-1]);
            }
            fdsa.push_back(a[j]);
            f[a[j]-1] = fdsa.size()-1;
        }
        for (int j : fdsa) {
            ans[j-1]++;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << ' ';
    }
    return 0;
}

