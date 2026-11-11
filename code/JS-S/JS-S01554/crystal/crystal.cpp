#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, minn, sum = 0;
int a[500005], d[500005], b[500005];
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    minn = 1;
    for (int i = 1; i < n; i++){
        d[i] = a[i + 1] - a[i];
        if (d[i] < d[minn]){
            minn = i;
        }
    }
    for (int i = 1; i < minn; i++){
        b[i] = a[minn] - a[i];
    }
    for (int i = minn; i <= n; i++){
        b[i] = a[i] - a[minn];
    }
    int l = minn - 1, r = minn + 1;
    while (l >= 1 && r <= n){
        if (b[l] < b[r] * (r - l + 1)){
            if (sum + b[l] <= m)
                sum += b[l--];
            else
                break;
        }
        else{
            if (sum + b[r] * (r - l + 1) <= m)
                sum += b[r] * (++r - l);
            else
                break;
        }
    }
    cout << r - l - 1;
    return 0;
}
