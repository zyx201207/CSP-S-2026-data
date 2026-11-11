#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 5e5 + 7;
using i128 = __int128;
ll n, m;
ll in[maxn];
i128 pre[maxn];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i){
        cin >> in[i];
    }
    sort(in + 1, in + n + 1);
    for(int i = 1; i <= n; ++i){
        pre[i] = pre[i - 1] + in[i];
    }
    int ans = 0, l = 0;
    for(int i = 1; i <= n; ++i){
        while(l <= i && (i128)in[i] * (i128)(i - l) > (i128)m + (i128)(pre[i]- pre[l])){
            l ++;
        }
        ans = max(ans, i - l);
    }
    cout << ans;
    return 0;
}
