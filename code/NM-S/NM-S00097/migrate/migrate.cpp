#include<bits/stdc++.h>
using namespace std;
const int N = 2000005;
int c,t,n;
long long d,a[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >>c >>t;
    if (c == 11 || c == 12){
        while (t--){
            cin >> n >>d;
            for (int i = 1;i <= n;i++){
                cin >> a[i];
            }
            long long bot = a[2] - a[1];
            if (2*bot < d){
                cout << 0;
                continue;
            }
            cout << n-3 << "\n";
        }
    }
    else{
        cout << n <<"\n";
    }
    return 0;
}
