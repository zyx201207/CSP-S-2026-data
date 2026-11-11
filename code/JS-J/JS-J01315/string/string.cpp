#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,a[N],l=1,r,ans;
char c[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>c[i];
    }
    r=n;
    while(l<r)
    {
        if(a[l]==a[r])
        {
            if(c[l]!=c[r])
            {
                ans+=a[l];
            }
            l++;
            r--;
            //cout<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<' '<<ans<<'\n';
        }
        else
        {
            if(a[l]>a[r])
            {
                if(c[l]!=c[r])
                {
                    ans+=a[r];
                }
                a[l]-=a[r];
                r--;
                //cout<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<' '<<ans<<'\n';
            }
            else
            {
                if(c[l]!=c[r])
                {
                    ans+=a[l];
                }
                a[r]-=a[l];
                l++;
                //cout<<l<<' '<<r<<' '<<a[l]<<' '<<a[r]<<' '<<ans<<'\n';
            }
        }
    }
    cout<<ans;
    return 0;
}
