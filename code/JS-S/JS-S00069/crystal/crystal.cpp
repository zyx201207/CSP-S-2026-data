#include <bits/stdc++.h>
using namespace std;
long long m, n;
long long a[500010], b[500010], ans[500010];
int l = 1, len = 1, sum;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ans[1] = 1;
    for (int i = 2; i <= n; i++){
        len++;
        sum += len * (a[i] - a[i - 1]);
        while(sum > m){
            sum -= a[i] - a[l];
            len--;
            l++;
        }
        ans[i] = len + 1;
    }
    long long ma = 0;
    for (int i = 1; i <= n; i++){
        ma = max(ans[i], ma);
    }
    cout << ma;
    return 0;
}
