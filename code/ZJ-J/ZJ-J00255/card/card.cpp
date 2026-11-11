#include<bits/stdc++.h>
using namespace std;
using ll = long long;
inline void read(ll&a)
{
    char s=getchar_unlocked();
    ll f=1;
    ll cnt=0;
    while(!isdigit(s))
    {
        if(s=='-')f=-1;
        s=getchar_unlocked();
    }
    while(isdigit(s))
    {
        cnt=cnt*10+s-'0';
        s=getchar_unlocked();
    }
    a=cnt*f;
}
void solve()
{
    ll n,m;
    read(n);
    read(m);
    vector<ll> a(n+2);
    vector<ll> las(m+2);
    bool le=1;
    ll un=0;
    for(ll i=1;i<=n;++i)
    {
        read(a[i]);
        las[a[i]]=i;
        if(a[i]<a[i-1]) le=0;
        if(i!=1 && a[i]!=a[i-1]) un++;
    }
    if(le)
    {
        for(ll i=1;i<=m;++i)printf("%lld ",las[i]);
    }
    else
    {
        vector<ll> ans(m+1);
        for(ll l=1;l<=n;++l)
        {
            stack<ll> stk;
            vector<bool> fac(m+1,0);
            for(ll i=l;i<=n;++i)
            {
                if(fac[a[i]])
                {
                    while(!stk.empty())
                    {
                        if(stk.top()==a[i])break;
                        fac[stk.top()]=0;
                        stk.pop();
                    }
                }
                else
                {
                    fac[a[i]]=1;
                    stk.push(a[i]);
                }
            }
            while(!stk.empty())
            {
                ans[stk.top()]++;
                stk.pop();
            }
        }
        for(ll i=1;i<=m;++i) printf("%lld ",ans[i]);
    }
}
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
}