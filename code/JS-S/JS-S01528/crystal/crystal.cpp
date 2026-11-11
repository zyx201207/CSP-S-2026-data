#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 3;
int n, m, a[N], ans;
bool fa = true;
int log_2(int x){
    int res = 0;
    while(x){
        res++;
        x >>= 1;
    }
    return res;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] != i + 1){
            fa = false;
        }
    }
    if(fa){
        if(m == 0){
            cout << 0;
            return 0;
        }
        ans = log_2(n);
        m--;
        unsigned long long pps = 1 << ans;
        int delt = 1;
        while(m > 0){
            if(pps < n && pps != 2){
                m--;
                pps <<= 1;
                continue;
            }
            if(m > pps - a[n - delt]){
                m -= pps - a[n - delt];
                pps <<= 1;
                ans++;
            }else{
                break;
            }
        }
        cout << ans;
        return 0;
    }
    return 0;
}