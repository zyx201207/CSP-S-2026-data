#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
const int maxm = 35;
int n, m, cnt[maxm], tot;
long long lg[maxm], a[maxn], ans, tmp;
bool cmp(long long a, long long b){
    return a > b;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("ans.out", "w", stdout);
    cin >> n >> m;
    lg[0] = 1;
    for(int i = 1;i <= 30;i++){
        lg[i] = lg[i - 1] * 2;
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        int id = upper_bound(lg, lg + 30, a[i]) - lg - 1;
        tot = max(tot, id);
    }
    for(int k = tot + 1; k >= 0;k--){
        for(int i = 1;i <= n;i++){
            if(a[i] >= lg[k])a[i] -= lg[k];
        }
        sort(a + 1, a + n + 1, cmp);
        tmp = max(lg[k] - 1, (long long)1);
        for(int i = 1; i <= m;i++){
            tmp &= a[i];
        }
        ans = max(ans, tmp);
    }
    cout << ans;
    return 0;
}
