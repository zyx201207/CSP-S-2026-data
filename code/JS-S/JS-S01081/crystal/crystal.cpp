#include<bits/stdc++.h>
using namespace std;

#define int long long

int n, m, cnt, res, v[500010], w[500100];

signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    for(int i = 1; i <= n; i++)
        w[i] = v[i] + w[i - 1];
    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        while(l < r){
            int mid = (l + r) / 2;
            if(w[i] - w[mid - 1] + m < 1ll * v[i] * (i - mid + 1))
                l = mid + 1;
            else
                r = mid;
        }
        res = max(res, i - l + 1);
    }
    cout << res << endl;
    return 0;
}