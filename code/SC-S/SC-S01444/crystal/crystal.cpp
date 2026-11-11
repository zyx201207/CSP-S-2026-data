#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  cout.tie(nullptr);
    ll n, m; cin>>n>>m;
    vector<ll> a(n + 1), s(n + 1, 0);
    for(int i=1;i<=n;i++){cin>>a[i];}
    sort(a.begin() + 1, a.end());
    for(int i=2;i<=n;i++){
        s[i] = s[i - 1] + (i - 1) * (a[i] - a[i - 1]);
    }
    ll ans = 0;
    for(int i=n;i;i--){
        int l = 1, r = i;
        while(l <= r){
            ll mid = (l + r >> 1);
            ll t = s[i] - s[mid] - (a[i] - a[mid]) * (mid - 1);
            //cout<<i<<" "<<mid<<" "<<t<<"\n";
            if(t <= m){r = mid - 1;}
            else{l = mid + 1;}
        }
        ans = max(ans, 1ll * (i - l + 1));
    }
    cout<<ans<<"\n";
    return 0;
}