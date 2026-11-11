#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    long long ans = 0, ans1 = 0;
    cin >> n;
    long long a[n+10] = {};
    char c[n+10] = {};
    for (int i = 0; i < n; i++){
        cin >> a[i] >> c[i];
        ans += a[i];
    }
    ans1 = ans/2;
    return 0;
}
