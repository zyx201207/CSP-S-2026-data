#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[200005],f[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(ll i = 1;i <= n;i++){
        for(ll j = m;j >= 1;j--){
            if(j == 1){
                f[j] = max(f[j],a[i]);
            }else{
                f[j] = max(f[j],f[j-1]&a[i]);
            }
        }
    }
    cout << f[m];
    return 0;
}
