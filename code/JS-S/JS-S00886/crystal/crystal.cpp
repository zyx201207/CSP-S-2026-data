#include <bits/stdc++.h>
using namespace std;

long long a[500055], sum[500055];

int main(){
    //14:39:45 first finish
    //14:41:59 all tasks correct
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for(long long i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(long long i = 1;i <= n;i++){
        sum[i] = sum[i - 1] + a[i];
    }
    long long mx = 1;
    for(long long i = 2;i <= n;i++){
        long long l = 1, r = i - 1, ans = 0;
        while(l <= r){
            long long mid = (l + r) / 2;
            if(a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m){
                ans = (i - mid + 1);
                r = mid - 1;
            }
            else l = mid + 1;
        }
        mx = max(mx, ans);
    }
    cout << mx << "\n";
    return 0;
}
