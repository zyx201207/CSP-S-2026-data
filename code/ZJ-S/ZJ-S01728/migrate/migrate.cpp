#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
using PII = pair <int,int>;
using LL = long long;
using ULL = unsigned long long;
template <typename T1,typename T2> void tomax (T1 &x,T2 y) {if (y > x) x = y;}
template <typename T1,typename T2> void tomin (T1 &x,T2 y) {if (y < x) x = y;}
#define endl '\n'
int tid;
const int N = 2000010;
int n;
LL m;
LL w[N];
int nxt[N];
#define pb push_back
bool check (int a,int b) {
    vector <int> vec;
    int p = a;
    while (p < b) {
        vec.pb (p);
        if (p == nxt[p]) return 0;
        p = nxt[p];
    }
    vec.pb (b);
    int cnt = 0;
    for (int i = 1;i < vec.size () - 1;i++) {
        if (vec[i] - 1 > vec[i - 1]) cnt += w[vec[i + 1]] - w[vec[i] - 1] <= m;
        if (vec[i] - 2 > vec[i - 1] && w[vec[i + 1]] - w[vec[i] - 2] <= m) return 0;
        // if (a == 1 && b == 9) cout << i << ' ' << (w[vec[i] - 1] - w[vec[i - 1] - 1] <= m && w[vec[i + 1]] - w[vec[i] - 1] <= m) << "================" << endl;
        if (i - 1 >= 1 && (i - 2 < 0 || vec[i - 1] - 1 > vec[i - 2]) && vec[i - 1] - 1 >= 1 && w[vec[i] - 1] - w[vec[i - 1] - 1] <= m && w[vec[i + 1]] - w[vec[i] - 1] <= m) return 0;
    }
    // if (cnt == 1) cout << a << ' ' << b << "====" << endl;
    // cout << "========" << endl << flush;
    return cnt == 1;
}
void mian () {
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> w[i];
    for (int i = 1,j = 1;i <= n;i++) {
        while (j + 1 <= n && w[j + 1] - w[i] <= m) j++;
        nxt[i] = j;
    }
    int ans = 0;
    for (int i = 1;i <= n;i++) {
        for (int j = i + 1;j <= n;j++) ans += check (i,j);
    }
    cout << ans << endl;
}
int main () {
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    ios :: sync_with_stdio (false),cin.tie (0),cout.tie (0);
    int T = 1;
    cin >> tid >> T;
    while (T--) mian ();
    return 0;
}