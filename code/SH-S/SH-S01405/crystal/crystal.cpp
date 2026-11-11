#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
int n, ans;
ll m, a[N], f[N];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%lld", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++){
        f[i] = f[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++){
        int l = 1, r = i;
        while (l < r){
            int mid = (l + r) >> 1;
            if ((i - mid + 1) * a[i] - (f[i] - f[mid - 1]) <= m){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d\n", ans);
}