#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1e6 + 9;
int n,d;
int isl[MAXN],ans[MAXN];
void solve(){
    cin >> n >> d;
    for(int i = 1;i <= n;i ++){
        cin >> isl[i];
    }
    cout << n % d << '\n';
    memset(isl + 1,0,n + 1);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    for(int i = 1;i <= t;i ++)  solve();
    return 0;
}
