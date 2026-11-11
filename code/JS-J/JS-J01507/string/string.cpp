#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10;
ll a[N];
char c[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,cnt=1,sum=0,ans=0;
    cin>>n;
    cin>>a[1]>>c[1];
    char last=c[1];
    sum+=a[1];
    for(ll i=2;i<=n;i++)//merge
    {
        ll x;
        char y;
        cin>>x>>y;
        sum+=x;
        if(y==last) a[cnt]+=x;
        else
        {
            a[++cnt]=x;
            c[cnt]=y;
            last=c[cnt];
        }
    }
    ll zchw=0;
    int l=1,r=cnt;
    if(l==r)
    {
        cout<<0;
        return 0;
    }
    while(l<r)
    {
        if(c[l]==c[r]) zchw=zchw+min(a[l],a[r])*2;
        if(a[l]>a[r])
        {
            a[l]-=a[r];
            r--;
        }
        else if(a[l]==a[r])
        {
            l++;
            r--;
        }
        else
        {
            a[r]-=a[l];
            l++;
        }
    }
    if(l==r) zchw=zchw+a[l];
    cout<<(sum-zchw)/2;
    return 0;
}
