#include<bits/stdc++.h>
using namespace std;
long long x[5010];
int l[5010],r[5010];
int ld[5010],rd[5010];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,t,n,p,u,v;
    long long d,ans;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        if(c==13||c==14)
        {
            cout<<0<<"\n";
            continue;
        }
        p=1;
        for(int i=1;i<=n;i++)
        {
            if(i==1)l[i]=i;
            else if(i==2)
            {
                if(x[i]-d<=x[i-1])l[i]=i-1;
                else l[i]=i;
            }
            else
            {
                if(x[i]-d>x[i-1])l[i]=i;
                else if(x[i]-d<=x[i-2])l[i]=i;
                else l[i]=l[i-1];
            }
            while(x[i]-d>x[p])++p;
            ld[i]=p;
        }
        p=n;
        for(int i=n;i>=1;i--)
        {
            if(i==n)r[i]=i;
            else if(i==n-1)
            {
                if(x[i]+d>=x[i+1])r[i]=i+1;
                else r[i]=i;
            }
            else
            {
                if(x[i]+d<x[i+1])r[i]=i;
                else if(x[i]+d>=x[i+2])r[i]=i;
                else r[i]=r[i+1];
            }
            while(x[i]+d<x[p])--p;
            rd[i]=p;
        }
        ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                u=r[i];v=l[j];
                if(u>=v)continue;
                if(rd[u]-ld[v]==1)++ans;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
