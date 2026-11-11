#include <iostream>
using namespace std;

long long a[2000005];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c, T;
    cin >> c >> T;
    while (T--){
        long long n, d;
        cin >> n >> d;
        for (int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if (a[2] - a[1] >= d){
            cout << 0 << '\n';
        } else {
            cout << n / (a[2] - a[1]) << '\n';
        }

    }
    return 0;
}
