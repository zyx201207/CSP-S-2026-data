#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,d;
int a[200010];
int f[200010];
int t[200010];
int two[200010];

int find1(int x)
{
    int l=1,r=n;
    int mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        if(a[mid]>=x)
        {
            r=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
    return l;
}

bool check(int l,int r)
{
    for(int i=l+1;i<=r;i++)
    {
        int k=f[i];
        if(k==i)
        {
            return false;
        }
        t[i]=INT_MAX;
        for(int j=k;j<i;j++)
        {
            t[i]=min(t[i],t[j]);
        }
        t[i]++;

    }

    int ji=0;
    for(int i=r-1;i>=max(f[r],l);i--)
    {
        if(t[i]==t[r]-1)
        {
            ji++;
        }
        if(ji>=3)
        {
            return true;
        }
    }
    if(ji==2)
    {
        return true;
    }
    return false;
}

main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t1;
    cin>>c>>t1;
    while(t1--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            f[i]=find1(a[i]-d);
        }
        if(c>=10)
        {
            long long ans=0;
            for(int i=2;i<=n;i++)
            {
                int k=f[i];
                if(k>=i-1)
                {
                    continue;
                }
                ans+=f[k+2]-f[k+1];
            }
            cout<<ans<<endl;
            continue;
        }
        long long ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(check(i,j))
                {
                    ans++;
                }
                for(int k=i;k<=j;k++)
                {
                    t[k]=0;
                }
            }

        }
        cout<<ans<<endl;
    }
}
