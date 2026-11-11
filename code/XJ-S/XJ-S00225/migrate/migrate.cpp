#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;

int n, d, x[N];
void solve(){
    cin >> n >> d;
    for(int i = 1; i <= n; i ++)
        cin >> x[i];
    cout << n <<'\n';
    return;
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c, t;
    cin >> c >> t;
    while(t --)
        solve();
    return 0;
}