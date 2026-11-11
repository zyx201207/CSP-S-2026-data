#include<bits/stdc++.h>
using namespace std;
long long a[500005] , cnt[300005] , mp[300005] , ans[500005];
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    long long n , m , _i; cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n;j++) cnt[i] = 0 , mp[i] = -1;
        _i = 0;
        for (int j = i;j <= n;j++){
            if (mp[j] == -1){
                _i++;
                cnt[_i] = a[j];
                mp[j] = _i;
            }else{
                long long num = mp[j];
                for (int k = mp[j];k <= _i;i++){
                    mp[k] = -1;
                    cnt[k] = 0;
                }
                _i = num;
                cnt[_i] = a[j];
            }
        }
        for (int j = 1;j <= _i;j++){
            if (mp[j] != -1) ans[a[j]]++;
        }
    }
    for (int i = 1;i <= m;i++) cout << ans[i] << ' ';
    return 0;
}
