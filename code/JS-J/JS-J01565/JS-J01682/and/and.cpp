#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n, m, a[N], ans;
vector<int> vec;
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i], vec.push_back(i);
    for(int i = 30;i >= 0;i--) {
        vector<int> _vec;
        for(int j : vec)
            if(a[j] & (1 << i)) _vec.push_back(j);
        if(_vec.size() >= m) {
            ans += (1 << i);
            vec.clear();
            for(int j : _vec) vec.push_back(j);
        }
    }
    cout << ans << endl;
    return 0;
}
