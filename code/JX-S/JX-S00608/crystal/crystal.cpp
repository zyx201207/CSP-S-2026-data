#include<bits/stdc++.h>
using namespace std;
int a[600005];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m, f = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if(n == 1){
        cout << 1;
        return 0;
    }
    if(m == 0){
        long long maxx = -1;
        long long f = 0;
        for(long long i = 1; i <= n; i++){
            if(a[i] == a[i - 1]){
                f++;
            }else{
                maxx = max(maxx, f);
                f = 1;
            }
        }
        maxx = max(maxx, f);
        cout << maxx;
        return 0;
    }else{
        long long i = 1;
        long long maxn = -1;
        for(long long j = 1; j <= n - maxn; j++){
            long long w = m;
            for(i = j + 1; i <= n; i++){
                m -= (a[i] - a[i - 1]) * (i - 1);
                if(m < 0) {
                    i--;
                    maxn = max(maxn, i);
                    break;
                }
            }
            if(m >= 0) {
                maxn = max(n - j + 1, maxn);
                cout << maxn;
                return 0;
            }
        }
        cout << maxn;
    }
    return 0;
}
