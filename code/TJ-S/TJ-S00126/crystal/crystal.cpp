#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans = -1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i = 0;i < n;++i) cin >> a[i];
    sort(a,a + n);
    for(int i = n - 1;i >= 1;--i){
        ll c = m,res = 0;
        for(int j = i;j >= 0;--j){
            if(a[i] - a[j] <= c){
                c -= a[i] - a[j];
                res++;
            }
            else break;
        }
        ans = max(ans,res);
    }
    cout << ans;
    return 0;
}
