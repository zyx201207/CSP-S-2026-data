#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],b[N],c[N],d[N],sb[N],jf[N];
ll cd(int i,int l)
{
    if(i<l) return 0;
    else return d[i]-(l-1)*sb[i]+jf[l];
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    // if(n<=5000)
    // {
    //     for(int l=1;l<=n;l++)
    //     {
    //          b[l]=0;
    //         for(int i=l+1;i<=n;i++)
    //             b[i]=a[i]-a[i-1],sb[i]=sb[i-1]+b[i];
    //         for(int i=l;i<=n;i++)
    //             c[i]=b[i]*(i-1);
    //         for(int i=l;i<=n;i++)
    //             d[i]=d[i-1]+c[i];
    //         for(int i=l;i<=n;i++)
    //             if(d[i]<=m) ans=max(ans,1ll*(i-l+1));
    //     }
    //     cout<<ans;
    //     return 0;
    // }
    int l=1;
    b[l]=0;
            for(int i=l+1;i<=n;i++)
                b[i]=a[i]-a[i-1],sb[i]=sb[i-1]+b[i];
            for(int i=l;i<=n;i++)
                c[i]=b[i]*(i-1);
            for(int i=l;i<=n;i++)
                d[i]=d[i-1]+c[i];
    // for(int i=l;i<=n;i++)
    //     cout<<d[i]<<" ";
    // cout<<"\n";
    for(int i=1;i<=n;i++)
        jf[i]=jf[i-1]+sb[i-1];
    // for(int i=1;i<=n;i++)
    //     cout<<jf[i]<<" ";
    // cout<<"\n";
    for(l=1;l<=n;l++)
    {
        // for(int i=l;i<=n;i++)
        //     cout<<cd(i,l)<<" ";
        // cout<<"\n";
        int cl=l,cr=n+1;
        while(cl+1<cr)
        {
            int mid=(cl+cr)>>1;
            if(cd(mid,l)<=m) cl=mid;
            else cr=mid;
        }
        ans=max(ans,1ll*(cl-l+1));
        // cout<<cl<<"\n";
    }
    cout<<ans;
    return 0;
}