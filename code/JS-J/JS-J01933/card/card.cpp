#include <bits/stdc++.h>
using namespace std;
int n, m, x[500005];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> x[i];
    }
    int a = n + m - 1;
    while(a > 0){
        cout << n << " " << m << " " << 1 << " " << 7;
        n -= 5;
        m += 7;
    }
    return 0;
}
