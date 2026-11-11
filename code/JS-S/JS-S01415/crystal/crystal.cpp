#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[500010],m,c[500010],h[500010];
signed main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    int f1=1,t;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    t=a[2]-a[1];
    for(int i=1;i<n;i++)
    {
        if(a[i+1]-a[i]!=t)
        {
            f1=0;
        }
        c[i+1]=a[i+1]-a[i];
    }
    for(int i=1;i<=n;i++)
    {
        h[i]=h[i-1]+c[i];
    }
    if(f1==1)
    {
        int r=0;
        while(m>0)
        {
            r++;
            m-=r*t;
        }
        if(m==0)
        {
            cout<<r;
            return 0;
        }
        else
        {
            cout<<r-1;
            return 0;
        }
    }
    int ans=0,ts=1;
    t=0;
    for(int i=2;i<=n;i++)
    {
        int k=i-1,ts=1,t=0;
        //cout<<a[i]<<" ";
        while(1)
        {
            t+=h[i]-h[k];
            //cout<<t<<" ";
            if(t>m)
            {
                break;
            }
            ts++;

            k--;
            if(k==0)
            {
                ts=i;
                break;
            }
        }
        //cout<<'\n';
        ans=max(ans,ts);
    }
    cout<<ans;
    return 0;
}
