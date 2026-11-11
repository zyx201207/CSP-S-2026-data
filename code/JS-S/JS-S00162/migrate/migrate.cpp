#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e6+5;
int n, d;
int x[N];

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    if(c == 11 || c == 12){
        while(t--){
            cin >> n >> d;
            for(int i=1; i<=n; i++){
                cin >> x[i];
            }
            int dis = x[2] - x[1];
            int k = d / dis;
            if(k <= 1){
                cout << 0 << '\n';
                continue;
            }
            else{
                if(n <= 2*k-1) cout << 0 << '\n';
                else cout << n - (2 * k - 1) << '\n';
                continue;
            }
        }
    }
    else{
        while(t--){
            bool flag = 1;
            cin >> n >> d;
            int dis = 0;
            for(int i=1; i<=n; i++){
                cin >> x[i];
            }
            dis = x[2] - x[1];
            for(int i=2; i<=n; i++){
                if(dis != x[i] - x[i-1]){
                    flag = 0;
                    break;
                }
            }
            if(flag == 0){
                cout << 0 << '\n';
            }
            else{
                int k = d / dis;
                if(k <= 1){
                    cout << 0 << '\n';
                    continue;
                }
                else{
                    if(n <= 2*k-1) cout << 0 << '\n';
                    else cout << n - (2 * k - 1) << '\n';
                    continue;
                }
            }
        }
    }
    return 0;
}