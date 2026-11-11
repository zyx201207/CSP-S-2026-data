#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll N=5e5+10;
ll a[N];
ll n,m;
ll ing=0;
ll maxx=0,r,l;
bool cmp(ll A,ll B)
{
    return A>B;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(ll i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    a[0]=a[1];
    r=l=maxx=1;
    for(ll i=1;i<=n;i++)
    {
        ing-=(r-l)*(a[i-1]-a[i]);
        l=i;
        while(ing+a[i]-a[r+1]<=m&&r+1<=n)
            r++,ing+=a[i]-a[r];
        maxx=max(maxx,r-l+1);
        // cout<<ing<<" ";
        // cout<<l<<" "<<r<<"\n";
    }
    cout<<maxx;
    return 0;
}