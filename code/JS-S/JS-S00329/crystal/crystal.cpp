#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define INF 0x7f7f7f7f
const int N = 5e5 + 10;
ll n,m;
ll a[N],s[N];
int ans = 0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= n;i++){
        s[i] = s[i - 1] + a[i];
    }
    int p = 0;
    for(int i = 1;i <= n;i++){
        while(p <= i && a[i] * (ll)(i - p) - (s[i] - s[p]) > m) p++;
        ans = max(ans,i - p);
    }
    cout << ans;
    return 0;
}
