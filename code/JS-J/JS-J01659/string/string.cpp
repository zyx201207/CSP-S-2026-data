#include<bits/stdc++.h>
using namespace std;
long long a[200005],c[200005];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,l=1,r;
    long long si=0,ls,ans=0,rs;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int ai;
        char ci;
        cin>>ai>>ci;
        c[i]=int(ci-'a');
        a[i]=ai;
        si+=ai;
        //cout<<z<<' '<<a[z]<<'\n';
    }
    ls=a[1];
    rs=a[n];
    if(c[1]!=c[n]) ans+=min(a[1],a[n]);
    r=n;
    while(ls+a[l+1]<=si/2||rs+a[r-1]<=si/2)
    {
        if(ls<rs)
        {
            while(ls+a[l+1]<=si/2&&ls+a[l+1]<=rs)
            {
                l++;
                ls+=a[l];
                if(c[l]!=c[r]) ans+=a[l];
            }
            if(ls+a[l+1]<=si/2)
            {
                int zzz=rs-ls;
                l++;
                ls+=a[l];
                if(c[l]!=c[r]) ans+=zzz;
            }
            else if(ls+a[l+1]<=si/2)
            {
                l++;
                ls+=a[l];
            }
        }
        else
        {
            while(rs+a[r-1]<=si/2&&ls>=rs+a[r-1])
            {
                r--;
                rs+=a[r];
                if(c[l]!=c[r]) ans+=a[r];
            }
            //if(l==99961&&r==99964) cout<<1<<' '<<r-1<<' '<<rs<<' '<<a[r-1]<<'\n';
            if(rs+a[r-1]<=si/2)
            {
                int zzz=ls-rs;
                r--;
                rs+=a[r];
                //if(l==99961&&r==99964) cout<<rs<<'\n';
                if(c[l]!=c[r]) ans+=zzz;
            }
            else if(ls+a[l+1]<=si/2)
            {
                l++;
                ls+=a[l];
            }
        }
        if(rs==ls)
        {
            if(ls+a[l+1]>si/2||rs+a[r-1]>si/2) break;
            l++;
            ls+=a[l];
        }
        //cout<<l<<' '<<ls<<' '<<r<<' '<<rs<<' '<<si/2<<'\n';
    }
    if(ls+rs<si) ans+=abs(ls-rs);
    cout<<ans<<'\n';
    return 0;
}
