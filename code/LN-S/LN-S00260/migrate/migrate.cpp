#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ll c,t;
    cin >> c >> t;
    while (t--){
        ll n,d,del;
        cin >> n >> d;
        ll x[n];
        for (ll i=0;i<n;i++) cin >> x[i];
        del = x[1] - x[0];
        if (d <= del){
            cout << 0 << '\n';
            continue;
        }
        if (n > (2*d-del)/del) cout << n - (2*d-del)/del << '\n';
        else cout << 0 << '\n';
    }
    return 0;
}
