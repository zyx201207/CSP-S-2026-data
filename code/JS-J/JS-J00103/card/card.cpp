#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,M = 3e5 + 5,A = 5e3;
typedef long long ll;
ll n,m,tp,a[N],t[M],st[N],ans[M];
bool vis[M],f[M];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }

    for (int i = n;i >= 1;i--){
        if (vis[a[i]] || f[st[tp]] == 1){
            for (;st[tp] != a[i];tp--){
                ans[st[tp]] += t[st[tp]] - i;
                vis[st[tp]] = 0;
                f[st[tp]] = 1;
            }
            ans[a[i]] += t[a[i]] - i;
            t[a[i]] = i;
        }else{
            st[++tp] = a[i];
            vis[a[i]] = 1;
            t[a[i]] = i;
        }
    }
    for (int i = 1;i <= tp;i++){
        ans[st[i]] += t[st[i]];
    }
    for (int i = 1;i <= m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}
