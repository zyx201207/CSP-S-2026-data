#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],ans[300005],t[500005];
bool b[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;++i) cin >> a[i];
    for(int i = 1;i <= n;++i){
        ll c = 0;
        for(int j = i;j <= n;++j){
            bool f = false;
            ll new_c = c;
            for(int k = 0;k < c;++k){
                if(t[k] == a[j]){
                    f = true;
                    new_c = k;
                }
                if(f) t[k] = 0;
            }
            c = new_c;
            t[c++] = a[j];
        }
        int res[300005] = {0};
        for(int j = 0;j < c;++j) res[t[j]] = 1;
        for(int j = 1;j <= m;++j) ans[j] += res[j];
    }
    for(int j = 1;j <= m;++j) cout << ans[j] << ' ';
	return 0;
}
