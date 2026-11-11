#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],ans=1,maxn=1,x,f;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(f==0&&a[i]==i);
        else
        {
            f=1;
        }
    }
    if(f==0)
    {
        for(int i=1;i<=n;i++)
        {
            m-=i;
            if(m<0)
            {
                m+=i;
                break;
            }
            ans++;
        }
        cout<<min(n,ans);
        return 0;
    }
    sort(a+1,a+1+n);

    for(int i=1;i<=n;i++)
    {
        ans=1;
        x=0;
        for(int j=i-1;j>=1;j--)
        {
            if(x+a[i]-a[j]<=m)
            {
                x+=a[i]-a[j];
                ans++;
            }
            else
            {
                break;
            }
        }
        maxn=max(maxn,ans);
    }
    cout<<maxn;
    return 0;
}
