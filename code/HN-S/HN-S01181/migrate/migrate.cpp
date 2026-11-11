#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 2e6 + 10;

int sub, T, n;
ll m, a[N];

namespace special_A{
    void solve(){
        if(m < (a[2] - a[1]) * 2){
            cout << 0;
            return ;
        }
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(sub == 11 || sub == 12){
        special_A::solve();
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> sub >> T;
    while(T--){
        solve();
    }
    return 0;
}
