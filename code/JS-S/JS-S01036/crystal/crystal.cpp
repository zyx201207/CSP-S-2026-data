#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,del##i##verme=int(n);i<del##i##verme;++i)
#define rep1(i,n) for(int i=1,parano##i##a=int(n);i<=parano##i##a;++i)
#define per(i,n) for(int i=int(n)-1;i>=0;--i)
#define per1(i,n) for(int i=int(n);i>=1;--i)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ldb;
const ll mod1=998244353;
const ll mod2=1000000007;
using namespace std;
unsigned time_related_rand()
{
    return unsigned(std::chrono::steady_clock::now().time_since_epoch().count());
}
int n;ll m,a[500005],s[500005];
int c=1;
bool check(int i,int cnt)
{
    return (a[i]*cnt-(s[i]-s[i-cnt])<=m);
}
int main()
{
    #ifndef DEBUG
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    #endif
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    rep1(i,n) cin>>a[i];
    sort(a+1,a+n+1);
    rep1(i,n) s[i]=s[i-1]+a[i];
    rep1(i,n)
    {
        while(c+1<=i&&check(i,c+1)) ++c;
    }
    cout<<c<<'\n';
    return 0;
}
/*
_i__e: _i__ ___ re_e__er _e
__i_ i_ _ _e__ __ere ___ _e__er_ e__e__ __e_e _r__ __e __r_ "reviver" _re re____e_ __ ___er_i_e_.
__r e_____e, __r__ _i_e "river" _re_'_ _____e_, ___ __r__ _i_e "____" _i____e_r.
___e ___ ___ re__ver __i_ _e__.
*/