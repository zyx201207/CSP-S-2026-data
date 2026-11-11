#include<bits/stdc++.h>
#define rep(a, b, c) for(int a=(b);a<=(c);a++)
#define rop(a, b, c) for(int a=(b);a>=(c);a--)
#define SZ(a) (int)a.size()-1
#define fi first
#define se second
#define mkp make_pair
using ll=long long;
using namespace std;

namespace MyCode{
    const int N=5e5+10;
    int n, ans;
    ll m, a[N], s[N];
    void Main(){
        cin>>n>>m;
        rep(i, 1, n) cin>>a[i];
        sort(a+1, a+n+1);
        rep(i, 1, n) s[i]=a[i]+s[i-1];
        int l=1, r=0;
        while(r++<n) {
            while((ll)(r-l+1)*a[r]-(s[r]-s[l-1])>m) l++;
            ans=max(ans, r-l+1);
        } cout<<ans<<'\n';
    }
}

int main(){
 freopen("crystal.in", "r", stdin);
 freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T=1;
    // cin>>T;
    // MyCode::init();
    while(T--) MyCode::Main();
    return 0;
}