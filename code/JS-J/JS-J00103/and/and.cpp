#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5 + 5;
ll n,m,a[N],b[N],c[N],idx[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        idx[i] = i;
    }
    for (int i = 29;i >= 0;i--){
        for (int id = 1;id <= n;id++){
            int k = a[idx[id]] & (1 << i);
            if (k){
                b[++b[0]] = idx[id];
            }else{
                c[++c[0]] = idx[id];
            }
        }
        if (b[0] >= m){
            n = b[0];
            for (int id = 1;id <= n;id++){
                idx[id] = b[id];
            }
        }
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
    }
    ll ans = (1 << 30) - 1;
    for (int i = 1;i <= n;i++){
        ans &= a[idx[i]];
    }
    cout << ans;
    return 0;
}
