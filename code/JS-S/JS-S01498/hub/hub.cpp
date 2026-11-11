#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll c, t, n, k, a[1000010], ans;

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> c >> t;
    for(int _ = 1;_ <= t;_++){
        cin >> n >> k;
        ans = n / 5;
        cout << ans << endl;
    }
    return 0;
}
