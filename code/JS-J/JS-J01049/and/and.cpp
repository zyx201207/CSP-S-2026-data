#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, ans, a[200050];
void dfs(ll x, ll num, ll res){
    if(num == m){
        ans = max(ans, res);
        return;
    }
    if(x > n)
        return;
    dfs(x + 1, num + 1, (num == 0 ? a[x] : res & a[x]));
    dfs(x + 1, num, res);
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    dfs(0, 0, 0);
    cout << ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
