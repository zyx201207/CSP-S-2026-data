#include <bits/stdc++.h>
using namespace std;
int t;
long long n, d;
long long a[2000010];
int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> t >> t;
    while(t--){
        cin >> n >> d;
        long long b = 0;
        bool bo = 0;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
            if(i == 1) {
                continue;
            }
            if(i == 2){
                b = a[2] - a[1];
            } else {
                if(a[i] - a[i - 1] != b){
                    bo = 1;
                }
            }
        }
        if(!bo){
            if(b * 2 <= d && b * 3 > d){
                cout << n - 3 << "\n";
            } else {
                cout << 0 << "\n";
            }
            continue;
        }
        cout << n / 2 << "\n";
    }
    return 0;
}
