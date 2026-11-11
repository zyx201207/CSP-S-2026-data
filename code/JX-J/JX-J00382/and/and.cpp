#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 5;
int n, m, ts13, ma;
int a[N], k[N];
bool cmp(int x,int y){
    return x > y;
}
signed main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
        ma = max(ma, a[i]);
        for(int k = 30;k >= 1;k--){
            if(a[i] == (1 << k) -1){
                ts13++;
            }
        }
    }
    sort(a + 1, a + 1 + n, cmp);
    if(ts13 == n){
        int l = a[1] & a[2] & a[3];
        cout << l;
        return 0;
    }
    for(int msk = 30; msk >= 1; msk--){
        if((1 << (msk + 1)) - 1 > ma)
            continue;
        int cnt = 0, f = 0, ans = 0;
        for(int i = 1;i <= n; i++){
            int t = (a[i] >> (msk-1)) & 1;
            if(t == 1){
                cnt++;
                if(f == 0)
                    f = 1, ans = a[i];
                else
                    ans &= a[i];
                k[cnt] = a[i];
                if(cnt >= m){
                    ans = k[1];
                    for(int i = 2;i <= m; i++)
                        ans &= k[i];
                    cout << ans;
                    return 0;
                }
            }
        }
        if(cnt == m){
            cout << ans ;
            return 0;
        }
    }
    int l = a[1] & a[2] & a[3];
    cout << l;
    return 0;
}
