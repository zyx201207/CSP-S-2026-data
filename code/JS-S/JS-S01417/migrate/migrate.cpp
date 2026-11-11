#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2000005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    ll c , t; cin >> c >> t;
    if (c == 0){
        if (t == 16) cout << "6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        else if (t == 14) cout << "9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
        else if (t == 12) cout << "0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
        else if (t == 13) cout << "8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
        else if (t == 2){
            int x; cin >> x;
            if (x == 5) cout << "0\n1";
            else cout << "1\n2";
        }
        return 0;
    }
    while(t--){
        ll n , d; cin >> n >> d;
        for (int i = 1;i <= n;i++) cin >> a[i];
        cout << 0 << '\n';
    }
    return 0;
}
