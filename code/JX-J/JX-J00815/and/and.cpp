#include <bits/stdc++.h>
using namespace std;
long long max1 = 0;
long long n, m;
long long a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (long long i=1; i<=n; i++){
        cin >> a[i];
        max1 = max(max1, a[i]);
    }
    if (m == 1){
        cout << max1;
        return 0;
    }
    else if (m == 2){
        long long max2 = 0;
        for (long long i=1; i<=n; i++){
            for (long long j=i+1; j<=n; j++){
                max2 = max(max2, a[i] & a[j]);
            }
        }
        cout << max2;
    }
    else cout << 7;
    return 0;
}
//15 pts
