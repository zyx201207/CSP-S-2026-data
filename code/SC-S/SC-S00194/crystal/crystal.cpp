#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll m, a[N], s[N];
ll sum(int l, int r){
    return a[r] * (r - l) - (s[r - 1] - s[l - 1]);
}
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n;
    scanf("%d%lld", &n, &m);
    for(int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int ans = 0;
    for(int i = 1; i <= n; i++){
        int l = 1, r = i;
        while(l < r){
            int mid = (l + r) >> 1;
            if(sum(mid, i) <= m) r = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    printf("%d\n", ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}