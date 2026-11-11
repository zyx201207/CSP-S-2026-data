#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define db cerr<<"fff"<<'\n';
#define int unsigned int
vector<int> a;
int n,m;
vector<int> f;
int dfs(int i,int a) {
    if (i == n && a==0)return UINT_MAX;
    else if (n-i<a)return 0;
    int fdsa = dfs(i+1,a-1);
    int rewq = dfs(i+1,a);
    int jkl = ::a[i];
    fdsa = fdsa & jkl;
    return (f[i]=(max(fdsa,rewq)));
}
signed main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    a.resize(n);
    f.resize(n,-1);
    int aflag = 1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!((a[i]+1)==(1<<__lg(a[i]+1))))aflag = 0;
    }
    if (m == 1) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans,a[i]);
        }
        cout << ans;
    } else if (m == n) {
        int ans = a[0];
        for (int i = 1; i < n; i++) {
            ans = ans & a[i];
        }
        cout << ans;
    } else if (m == 2) {
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; i++) {
                ans = max(ans,a[i]&a[j]);
            }
        }
        cout << ans;
    } else if (aflag) {
        sort(a.begin(),a.end());
        cout<<a[n-m];
    }
    else cout<<dfs(0,m);

    return 0;
}

