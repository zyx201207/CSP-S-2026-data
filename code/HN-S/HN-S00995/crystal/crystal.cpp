#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll qpow(ll n,ll m,ll mod)
{
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    ll res=1;
    while(m)
    {
        if(m&1)res=res*m%mod;
        n=n*n%mod;
        m>>1;
    }
    return 0;
}
