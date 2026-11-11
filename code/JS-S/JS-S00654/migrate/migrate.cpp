#include <iostream>
#include <cstring>
#define mas 2000010
#define int long long
using namespace std;

int c, t;
int n, d;
int x[mas];

void solve(){
    cin >> n >> d;
    for (int i=1;i<=n;i++)
        cin >> x[i];
    int gc=x[2]-x[1];
    if (gc<0) gc*=-1;
    if (d<gc*2) cout << "0" << endl;
    else {
        cout << n-3 << endl;
    }
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    cin >> c >> t;

    while (t--){
        solve();
    }
    

    return 0;
}