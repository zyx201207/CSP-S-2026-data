#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5+5;
int cc,n,m,a[N],dd,q,k[505];
vector<pair<int,int>> mp[N];
vector<int> st[N];
void solve(){
    int x,y;
    cin >> x >> y;
    int ans = a[x] + a[y];
    for (auto ii:st[x]) for (auto jj:st[y]) {
        if (ii == jj) {
            for (auto p:mp[ii])
                if (p.first == x || p.first == y) ans += p.second;
            cout << ans << "\n";
            return ;
        }
    }
   cout << ans * (y-x) << "\n";
   return ;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> cc >> n >> m >> dd >> q;
    for (int i = 1;i <= m;i++) cin >> a[i];
    for (int i = 1;i <= n;i++) {
        cin >> k[i];
        for (int j = 1;j <= k[i];j++) {
            int aa,tt;
            cin >> aa >> tt;
            mp[i].push_back({aa,tt});
            st[aa].push_back(i);
        }
    }
    while (q--) solve();
    return 0;
}
