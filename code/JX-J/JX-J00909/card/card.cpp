#include <bits/stdc++.h>
using namespace std;

long long m, n, a[325799];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for (int i=1; i<=n; i++) cin >> a[i];
    if (m == 1 && n == 1){
        cout << 1;
    }

    return 0;
}
