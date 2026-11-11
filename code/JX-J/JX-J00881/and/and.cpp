#include <bits/stdc++.h>
using namespace std;
int n,m,x[200005];
long long ans=0,p;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool j=1;
    for(int i=1; i<=n; i++)
    {
        cin>>x[i];
        if(x[i]%2==0)
        {
            j=0;
        }
    }
    if(n==1)
    {
        cout<<x[1];
        return 0;
    }
    if(m==2)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=i+1; j<=n; j++)
            {
                if(x[i]&x[j]>ans)ans=x[i]&x[j];
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n)
    {
        ans=x[1];
        for(int i=2; i<=n; i++)
        {
            ans=ans&x[i];
        }
        cout<<ans;
        return 0;
    }
    if(j)
    {   sort(x+1,x+n+1);
        p=x[1];
        for(int i=n-1; i>=n-m; i++)
        {
            p=p&x[i];

        }cout<<p;return 0;

    }
    if(m=n-1)
    {
        ans=x[1];
        p=0;
        for(int i=2; i<=n; i++)
        {
            ans=ans&x[i];
        }
        for(int i=1; 1<=n; i++)
        {
            if(ans&x[i]>p)
            {
                p=ans&x[i];
            }
        }
        cout<<p;
        return 0;
    }
    return 0;
}
