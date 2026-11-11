#include<bits/stdc++.h>
#define N 500005
#define int long long
using namespace std;
int n, m, maxn, a[N], d[N], lg[N], st[N][21];
int ask(int l, int r){
    int len = lg[r - l + 1];
    return max(st[l][len], st[r - (1 << len) + 1][len]);
}
bool check(int l, int r){
    int sum = d[r] - d[l - 1];
    int cnt = ask(l, r);
    return (cnt * (r - l + 1) - sum <= m);
}
signed main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    lg[0] = -1;
    for(int i = 1; i <= n; i++){
        d[i] = d[i - 1] + a[i];
        st[i][0] = a[i];
        lg[i] = lg[i / 2] + 1;
    }
    for(int j = 1; j <= lg[n]; j++){
        for(int i = 1; i + (1 << j) - 1 <= n; i++){
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    for(int i = 1; i <= n; i++){
        int l = i, r = n, ans = i - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(check(i, mid)){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        maxn = max(maxn, ans - i + 1);
    }
    cout << maxn;
    return 0;
}
