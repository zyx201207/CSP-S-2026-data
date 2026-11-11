#include <bits/stdc++.h>
using namespace std;
int n, a[200005], cnt = 0;
string b[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i=1; i<=n; ++i){
        cin >> a[i];
        cin >> b[i];
    }
    if (n%2 == 0){
        for (int i=1; i<=n/2; ++i){
            if (b[i] != b[n-i+1]) cnt += min(a[i], a[n-1]);
        }
    }
    else {
        for (int i=1; i<=n/2; ++i){
            if (b[i] != b[n-i]) cnt += min(a[i], a[n-1]);
        }
    }
    cout << cnt;

    return 0;
}
