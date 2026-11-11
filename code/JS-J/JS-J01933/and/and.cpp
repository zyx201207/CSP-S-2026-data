#include <bits/stdc++.h>
using namespace std;
int a, b, n[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> a >> b;
    for (int i = 1;i <= a;i++){
        cin >> n[i];
    }
    sort(n + 1, n + 1 + a);
    cout << n[3];
    return 0;
}
