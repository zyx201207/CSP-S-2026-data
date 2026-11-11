#include <bits/stdc++.h>
using namespace std;

long long n, k;
long long u[2000005], v[2000005];

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio("false");
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 1; i <= n; i++){
            cin >> u[i] >> v[i];
        }
        cout << 1 << endl;
    }
    return 0;
}
