#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==1)
    {
        int maxn=0;
        for (int i = 1;i<=n;i++)
        {
            int x;
            cin>>x;
            maxn=max(maxn,x);
        }
        cout<<maxn;
        return 0;
    }
    if(m==n||m==n-1)
    {
        int ans;
        cin>>ans;
        for (int i = 2;i<=n;i++)
        {
            int x;
            cin>>x;
            ans=(ans&x);
        }
        cout<<ans;
        return 0;
    }
    if(m==2)
    {
        int a[2010];
        int maxn=0;
        for (int i = 1;i<=n;i++)
        {
            cin>>a[i];
            for (int j = 1;j<i;j++)
                maxn=max(maxn,(a[i]&a[j]));
        }
        cout<<maxn;
    }
    return 0;
}
