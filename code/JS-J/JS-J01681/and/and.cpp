#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,cnt[40],bit;
struct num{
    int v;
    int b[40];
}a[200010];
bool cmp(num x,num y){
    return x.v > y.v;
}
bool check(int i){
    return a[i].b[bit];
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i].v;
        for(int x = 0;x < 31;x++){
            if((a[i].v >> x) & 1){
                cnt[x]++;
                a[i].b[x]++;
            }
            // cout << b[i][x] << ' ';
        }
        // cout << '\n';
    }
    for(int i = 30;i >= 0;i--){
        if(cnt[i] >= m){
            bit = i;
            break;
        }
        // cout << cnt[i] << ' ';
    }
    // cout << '\n';
    sort(a + 1,a + 1 + n,cmp);
    int ans = (1ll << 32) - 1,c = 1;
    for(int i = 1;i <= n && c <= m;i++){
        if(!check(i)){
            // cout << i << ' ' << a[i].v << '\n' << '\n';
            continue;
        }
        c++;
        // cout << c << ' ';
        // cout << a[i].v << '\n';
        ans &= a[i].v;
    }
    if(ans == (1ll << 32) - 1) ans = 0;
    cout << ans << '\n';
    return 0;
}