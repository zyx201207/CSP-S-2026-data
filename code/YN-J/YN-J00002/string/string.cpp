#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;
const int N = 2e5 + 5;
int a[N];
char c[N];
void solve(){
    int n; cin >> n;
    for(int i = 1;i <= n;i++) cin >> a[i] >> c[i];
    int l = 1,r = n,ans = 0;
    while(l <= r){
        if(a[l] == a[r]){
            if(c[l] != c[r]) ans += a[l];
            a[l] = a[r] = 0;
            l++;
            r--;
        }else if(a[l] > a[r]){
            if(c[l] != c[r]) ans += a[r];
            a[l] -= a[r];
            a[r] = 0;
            r--;
        }else{
            if(c[l] != c[r]) ans += a[l];
            a[r] -= a[l];
            a[l] = 0;
            l++;
        }
    }
    cout << ans;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tid,T = 1;
    while(T--) solve();
}

// expect 100 pts