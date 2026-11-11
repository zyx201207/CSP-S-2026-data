#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[100010];
char c[100010];

signed main(){
    freopen("string6.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> c[i];
        sum += a[i];
    }/*
    int l = 1, r = n, cnti = a[1], cntj = a[n];
    int ans = 0;
    while (cnti <= sum / 2 && cntj <= sum / 2){
        if (cnti > cntj){
            if (c[l] != c[r]) ans += cntj - (cnti - a[l]);
        }
        else if (cnti < cntj){
            if (c[l] != c[r]) ans += cnti - (cntj - a[r]);
        }
        else{
            if (c[l] != c[r]) ans += min(cntj - cnti + a[l], cnti - cntj + a[r]);
        }
        if (cnti == cntj){
            cnti += a[++l];
            cntj += a[--r];
        }
        else if (cnti < cntj){
            cnti += a[++l];
        }
        else cntj += a[--r];

    }
    if (cnti <= sum / 2){
        cntj = sum / 2;
        --r;
        while (cnti <= sum / 2){
            cnti += a[++l];
            if (c[l] != c[r]) ans += cnti - (cntj - a[r]);
        }
    }
    if (cntj <= sum / 2){
        cnti = sum / 2;
        ++l;
        while (cntj <= sum / 2){
            cnti += a[--r];
            if (c[l] != c[r]) ans += cntj - (cnti - a[l]);
        }
    }
    cout << ans << "\n";*/
    string s = "?";
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= a[i]; j++){
            s = s + c[i];
        }
    }
    int ans = 0;
    for (int i = 1; i <= sum / 2; i++){
        ans += (s[i] != s[sum + 1 - i]);
    }
    cout << ans << "\n";
    return 0;
}
