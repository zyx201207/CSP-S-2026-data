#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000001], b[2000001];
signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n, d;
        cin >> n >> d;
        for(int i = 1; i<=n; i++){
            cin >> a[i];
            b[i] = a[i]-a[1];
        }
        cout << n-(d*2)+1 << endl;
    }
    return 0;
}