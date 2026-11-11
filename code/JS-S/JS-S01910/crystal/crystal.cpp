#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005],b[500005],q,w;
bool jiancha(int e)
{
    for(int i=e+1;i<=q;i++)if(e*a[i]-b[i-1]+b[i-e-1]<=w)return true;
    return false;
}
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int e=1,r,t;
    cin>>q>>w;
    r=q-1;
    for(int i=1;i<=q;i++)cin>>a[i];
    sort(a+1,a+q+1);
    for(int i=1;i<=q;i++)b[i]=b[i-1]+a[i];
    while(e<r)
    {
        t=(e+r+1)/2;
        if(jiancha(t))e=t;
        else r=t-1;
    }
    cout<<r+1;
}
