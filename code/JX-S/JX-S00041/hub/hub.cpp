#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int nsid, t, n, k;
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> nsid >> t;
    while(t--){
        cin >> n >> k;
        if(n == k){
            cout << 0 << "\n";
            continue;
        }
        for(int i = 1, x, y; i < n; i++)cin >> x >> y;
        cout << ceil((n / 2) * 1.0 / (k + 1)) << "\n";
    }
}
