#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
#define debug cout << "ok" << endl

const int N = 2e5 + 10;
const int mod = 1e9 + 7;
const int inf = 1e9 + 10;

int n, m;

int a[N];

vector<vector<int> > vec(N);

bool check(int x) {
    // za quan shi tu lun
    if (rand() % 2 == 0) return 0;
    return 1;
}
// J zha le T2 mei tiao chu lai sai hou yi kan T3 hui zheng jie T4 hui bao li po beng le
// S neng you 1= ma T1 wei zheng jie zui hou yi ge da yang li mei guo qian mian ji ge guo le
// qi wang 75+0+0+0 JL neng you 1= ma
// zui hou yi nian le
// oi-chat .netlify .app 
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    // za zhe me nan
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << r + 1;
    return ;
}

signed main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c; cin >> c;
    int T = 1; cin >> T;
    while (T--) solve();
    return 0;
}