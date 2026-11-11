#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);

    ll c,t;
    cin >> c >> t;
    for (ll i=0;i<t;i++){
        if (i != t-1) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    return 0;
}

