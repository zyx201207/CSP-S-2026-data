#include <bits/stdc++.h>
#define int long long;
using namespace std;
int n, m, a[200005];
bool yes[200003][33], sur[200003];
int t[35];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        int bit = 0;
        while(a[i]){
            yes[i][++bit] = a[i] % 2;
            t[bit]++;
            a[i] >>= 1;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)sur[i] = 1;
    for (int i = 32; i >= 1; i--){
        if (t[i] >= m){
            start = i;
            break;
        }
    }
    for (int i = start; i >= 1; i--){
        int cur = 0;
        for (int j = 1; j <= n; j++)tmp[j] = sur[j];
        for (int j = 1; j <= n; j++){
            if (!yes[j][i])tmp[j] = 0;
            if (tmp[j])cur++;
        }
        if (cur >= m){
            ans += (l << (i - 1));
            for (int j = 1; j <= n; j++)sur[j] = tmp[j];
        }
    }
    cout << ans;
}
