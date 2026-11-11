#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500001];
long long ly[500001];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "r", stdout);
    cin >> n >> m;
    for(long long i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    long long CHAZHI;
    for(long long i = 1; i <= n; i++){
        CHAZHI = a[i] - a[i - 1];
        ly[i] = ly[i - 1] + CHAZHI * (i - 1);
        if(ly[i] > m){
            cout << i - 1 << '\n';
            return 0;
        }
    }
    cout << n;
    return 0;
}
