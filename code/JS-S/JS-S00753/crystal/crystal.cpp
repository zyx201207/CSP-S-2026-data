#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll n,m,a[500005],d[500005],sum = 0,cnt[500005],ans = 1;
bool flag = 0;

int main(){
    for(ll i = 1;i <= 500005;i++){
        cnt[i] = 1;
    }
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(ll i = 1;i <= n;i++){
        cin >> a[i];
    }
    sort(a+1,a+n+1);
    for(ll i = 2;i <= n;i++){
        d[i] = a[i] - a[i-1];
        sum += (i - 1) * d[i];
        if(d[i] != d[i-1]&&i >= 3){
            flag = 1;
        }
    }
    if(sum <= m){
        cout << n;
        return 0;
    }
    if(!flag){
        for(ll i = 1;i <= n;i++){
            ll mul = i * (i + 1) * d[2] / 2;
            if(mul > m){
                cout << i;
                return 0;
            }
        }
        cout << n;
    }
    for(ll i = 2;i <= n;i++){
        ll s = 0;
        for(ll j = i - 1;j >= 1;j--){
            s += (a[i] - a[j]);
            if(s <= m){
                cnt[i]++;
            }else{
                break;
            }
        }
        ans = max(ans,cnt[i]);
    }
    cout << ans;
    return 0;
}
