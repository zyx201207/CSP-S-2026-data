//I love Nagato Yuki forever!!!
//14:50
#include<bits/stdc++.h>
using namespace std;
namespace Z3k7223{
    #define ll long long
    const int N=5e5+10;
    int n;
    ll m,a[N],s[N];
    inline bool check(ll l,ll r){
        return m>=(ll)(r-l+1)*a[r]-(s[r]-s[l-1]);
    }
    void solve(){
        cin>>n>>m;
        for(int i=1;i<=n;i++)cin>>a[i];
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
        int l=1,ans=0;
        for(int i=1;i<=n;i++){
            while(!check(l,i))++l;
            ans=max(ans,i-l+1);
        }
        cout<<ans<<'\n';
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    Z3k7223::solve();
    return 0;
}