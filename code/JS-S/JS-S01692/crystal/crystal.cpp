#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 5;
ll n,m;
ll a[MAXN],k[MAXN];
ll c[250];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    bool f1 = 1,f2 = 1;
    ll d;
    for(int i = 0;i < n;i++){
        cin>>a[i];
        if(a[i] != i + 1){
            f1 = 0;
        }
        if(i == 1){
            d = a[1] - a[0];
        }
        if(i > 1){
            if(a[i] - a[i - 1] != d){
                f2 = 0;
            }
        }
    }
    if(n <= 5000){
        sort(a,a + n);
        int maxn = 0;
        for(int i = 0;i < n;i++){
            for(int j = 0;j < i;j++){
                k[j] = a[i] - a[j];
            }
            ll l = 0;
            int ans = 0;
            for(int j = i - 1;j >= 0;j--){
                l += k[j];
                if(l <= m){
                    ans++;
                }else{
                    break;
                }
            }
            maxn = max(maxn,ans);
        }
        cout<<maxn + 1;
    }else if(f1){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            ll k = i * (i - 1);
            k /= 2;
            if(k <= m)ans = i;
            else break;
        }
        cout<<ans;
    }else if(f2){
        int ans = 0;
        for(int i = 1;i <= n;i++){
            ll k = i * (i - 1) * d;
            k /= 2;
            if(k <= m)ans = i;
            else break;
        }
        cout<<ans;
    }else{
        for(int i = 0;i < n;i++){
            c[a[i] + 100]++;
        }
        ll takem = 0,nowtake = 0;
        ll ans = c[0];
        int i;
        for(i = 1;i <= 200;i++){
            takem += c[i - 1];
            nowtake += takem;
            if(nowtake <= m){
                ans += c[i];
            }else{
                break;
            }
        }
        nowtake -= takem;
        ans += (m - nowtake);
        cout<<ans;
    }
    return 0;
}