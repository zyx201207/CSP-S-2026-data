#include<bits/stdc++.h>
using namespace std;

using LL = long long;
const int N = 5e5+5;

LL a[N], sum[N], n, m;

bool ckeck(int len){
    LL cnt = 0;
    for(int i = 1; i + len - 1 <= n; i ++){
        cnt = a[i+len-1]*len - (sum[i + len - 1] - sum[i - 1]);
        if(cnt <= m)return true;
    }
    return false;
}

int main(){

    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        cin >> a[i];
    }

    sort(a+1, a+n+1);

    for(int i = 1; i <= n; i ++){
        sum[i] = sum[i-1] + a[i];
    }

    LL l = 1, r = n, mid, ans = -1;
    while(l <= r){
        mid = l + (r-l)/2;
        if(ckeck(mid)){
            ans = mid;
            l = mid + 1;
        }else{
            r = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}