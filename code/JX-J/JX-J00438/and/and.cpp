#include <bits/stdc++.h>

#define ll long long
using namespace std;
int a[200010];
int n, m;
ll ans = 0;
/*
void dfs(int i, ll x, int cnt) {
    if(i == n + 1){
        if(cnt == m) ans = max(x, ans);
        return;
    }
    if(cnt <= m) {
        dfs(i + 1, x & a[i], cnt + 1);
        dfs(i + 1, x & a[i], cnt);
    }
    else {
        ans = max(x, ans);
        return;
    }


return;
}*/
int main() {
freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    if(m == 1){
        int ans2=0;
        for(int i=1;i<=n;i++)ans2=max(a[i],ans2);
        cout<<ans2<<endl;
        return 0;
    }
    if(n == m){
        int ans2=a[1];
        for(int i=1;i<=n;i++)ans2=ans2&a[i];
        cout<<ans2<<endl;
        return 0;
    }

    cout << ans << endl;
    return 0;
}
