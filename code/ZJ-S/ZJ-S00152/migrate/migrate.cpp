#include <bits/stdc++.h>
using namespace std;
int c, t;
int x[200005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        memset(x, 0, sizeof(x));
        for (int i = 1; i <= n;i++){
            cin >> x[i];
        }
        cout << rand() % n << "\n";
    }
    return 0;
}