#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[200005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    long long maxn = 0;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        maxn = max(maxn, a[i]);
    }
    if(m == 1){
        cout << maxn;
        return 0;
    }
    if(m == n){
        long long an = a[1];
        for(int i = 2;i <= n;i++){
            an &= a[i];
        }
        cout << an;
        return 0;
    }
    if(m == 2){
        long long maxans = 0;
        for(int i = 1;i < n;i++){
            for(int j = i + 1;j <= n;j++){
                long long ans = a[i] & a[j];
                maxans = max(ans, maxans);
            }
        }
        cout << maxans;
        return 0;
    }
    if(m == n - 1){
        long long maxans = 0;
        for(int i = 1;i <= n;i++){
            long long ans;
            bool st = 1;
            for(int j = 1;j <= n;j++){
                if(j == i) continue;
                if(st == 1){
                    ans = a[j];
                }
                ans &= a[j];
                maxans = max(ans, maxans);
            }
        }
        cout << maxans;
        return 0;
    }
    return 0;
}
