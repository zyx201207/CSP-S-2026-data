#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[100005],c[100005],ans[1000005];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        int now=0;
        for(int j=i;j<=n;j++)
        {
            int t=1;
            for(int k=1;k<=now;k++)
            {
                if(c[k]==a[j])
                {
                    t=0;
                    now=k;
                    break;
                }
            }
            if(t)
            {
                now++;
                c[now]=a[j];
            }
        }
        for(int j=1;j<=now;j++)
        {
            ans[c[j]]++;
            c[j]=0;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
