#include<bits/stdc++.h>
using namespace std;
long long t,n,c,m,a[2000006],d,cnt;
void solve(){
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    if (n == 1){
        cout << 0 << '\n';
        return;
    }
    d = a[2]-a[1];
    cnt = m/d;
    if (cnt <= 1){
        cout << 0 << '\n';
        return;
    }
    cnt = cnt*2-1;
    //cout << cnt;
    cout << max(n-cnt+1,0LL) << '\n';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--)
        solve();
    return 0;
}
