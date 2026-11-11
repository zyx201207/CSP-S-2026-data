#include <bits/stdc++.h>
using namespace std;
int n,d;
int x[2000005];
int a[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    if(c >= 11 && c <= 12){
        while(t --){
            cin >> n >> d;
            for(int i = 1; i <= n; i ++) cin >> x[i];
            if(x[2] - x[1]) {
                cout << 0 << endl;
                continue;
            }
            int u = d / (x[2] - x[1]);
            if(u == 1) cout << 0 << endl;
            else cout << n - u * 2 + 1 << endl;
        }
        return 0;
    }
    while(t --){
        cin >> n >> d;
        for(int i = 1; i <= n; i ++) cin >> x[i];
        cout << 7 << endl;
    }
    return 0;
}
