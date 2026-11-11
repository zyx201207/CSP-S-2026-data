#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 5;
const ll V = 1e12 + 5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
int n;
ll s[N], a[N], m;
bool check(int frm, int to){
    ll len = to-frm+1;
    ll ned = len * a[to];
    ll hven = s[to] - s[frm-1];
    return hven + m >= ned;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for(int i= 1; i<= n; i++){
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+1+n);
    for(int i= 1; i<= n; i++)   s[i] = s[i-1] + a[i];
    //, printf("%d ", s[i])

    int res = 1;
    for(int i= 1; i<= n; i++){
        int ans = i;
        int L = 1, R = i;
        while(L<= R){
            int mid = (L+R) >> 1;
            if(check(mid, i)){
                R = mid-1;
                ans = min(ans, mid);
            }
            else L = mid+1;
        }
        res = max(res, i-ans+1);
    }

    printf("%d", res);
    return 0;
}
