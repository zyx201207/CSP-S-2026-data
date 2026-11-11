#include <bits/stdc++.h>
using namespace std;

#define il inline
#define For(i, a, b) for(long long i = (a);i <= (b);++i)
#define _For(i, a, b) for(long long i = (a);i >= (b);--i)
const long long maxn = 5e5 + 5;
long long n, m;
long long a[maxn], sum[maxn];
int L, R, mid, ans;

il bool check(int cnt){
    _For(i, n, cnt){
        if(a[i] == a[i + 1])  continue;
        long long tmp = cnt * a[i] - m;
        if(sum[i] - sum[i - cnt] >= tmp)  return true;
    }
    return false;
}

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    For(i, 1, n)  cin>>a[i];
    sort(a + 1, a + n + 1);
    For(i, 1, n)  sum[i] = sum[i - 1] + a[i];
    L = 1, R = n;
    while(L <= R){
        mid = (L + R) >> 1;
        if(check(mid)){
            ans = mid;
            L = mid + 1;
        }
        else  R = mid - 1;
    }
    cout<<ans<<'\n';
    return 0;
}
