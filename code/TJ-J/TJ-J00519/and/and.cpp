#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
ll n,m,a[200009];
bool cmp(ll x,ll y)
{
    return x>y;
}
ll _and(ll x,ll y)
{
    string resx="",resy="";
    while(x!=0)
    {
        ll d=x%2;
        resx+=(char)(d+48);
        x/=2;
    }
    reverse(resx.begin(),resx.end());
    while(y!=0)
    {
        ll d=y%2;
        resy+=(char)(d+48);
        y/=2;
    }
    string res="";
    for(int i=0;i<min(resx.size(),resy.size());i++)
    {
        if(resx[i]=='1'&&resy[i]=='1') res+='1';
        else res+='0';
    }
    //return resy;
    //return res;
    ll ans666=0;
    for(int i=0;i<res.size();i++)
    {
        if(res[i]=='1')
        {
            ll jia=(ll)pow(2,i);
            ans666+=jia;
        }
    }
    return ans666;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    ll ans=a[1];
    sort(a+1,a+n+1,cmp);
    for(ll i=2;i<=m;i++) ans=_and(ans,a[i]);
    cout<<ans;
    return 0;
}
