#include <bits/stdc++.h>
using namespace std;
long long a[200010];
int main(){

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    sort(a, a+n);

    cout << a[m];


    return 0;
}

