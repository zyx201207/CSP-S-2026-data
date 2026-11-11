#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 5e5 + 15;
int n;
ll m,a[N],sum[N];
void solve(){
    cin >> n >> m;
    for(int i = 1;i <= n;i ++)
        cin >> a[i];
    sort(a + 1,a + 1 + n);
    for(int i = 1;i <= n;i ++)
        sum[i] = sum[i - 1] + a[i];
    int maxn = 1,fr = 0;
    for(int i = 1;i <= n;i ++){
        while(a[i] * (i - fr) - (sum[i] - sum[fr]) > m) fr ++;
        maxn = max(maxn,i - fr);
    }
    cout << maxn << '\n';
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int T = 1;
    while(T --) solve();
    return 0;
}