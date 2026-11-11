#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll m,a[500005],c[500005];

bool check(int x,int y)
{
    ll res=c[y];
    for(int i=1;i<x;i++)
    {
        res-=(a[y]-a[i]);
    }
    return res<=m;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    bool f=1;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<n;i++)
        if(a[i]-a[i-1]!=a[i+1]-a[i])
        {
            f=0;break;
        }
    if(f==1)
    {
        ll d=a[2]-a[1];
        ll s=0;
        for(int i=1;i<n;i++)
        {
            s+=i*d;
            if(s>m)
            {
                cout<<i<<'\n';
                return 0;
            }
        }
        cout<<n<<'\n';
        return 0;
    }

    int p=1;
    for(int i=2;i<=n;i++)
    {
        c[i]=c[i-1]+p*(a[i]-a[i-1]);
        p++;
    }

    int ii=1,ans=1;
    for(int i=2;i<=n;i++)
        if(c[i]>m)
        {
            ii=i;
            ans=i-1;
            break;
        }
    for(int i=ii;i<=n;i++)
    {
        int pos=i;
        int l=1,r=i;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid,i))
            {
                r=mid-1;
                pos=mid;
            }
            else
                l=mid+1;
        }
        ans=max(ans,i-pos+1);
    }
    cout<<ans<<'\n';
    return 0;
}
