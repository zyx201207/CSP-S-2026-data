#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int ans[300005];
int zt[300005],ii;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n==m)
    {
        for(int i=1;i<=n;i++)
        {
            ans[a[i]]=i;
        }
        for(int i=1;i<=m;i++)
        {
            if(i==1) cout<<ans[i];
            else cout<<" "<<ans[i];
        }
        return 0;
    }
    if(m==1)
    {
        cout<<n<<endl;
        return 0;
    }
    if(m==2)
    {
        int b[3]={0,0,0};
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[n]) b[a[n]]++;
            if(a[i]!=a[n])
            {
                b[a[i]]++;
                b[a[n]]++;
            }
        }
        cout<<b[1]<<" "<<b[2]<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ii=0;
        for(int j=i;j<=n;j++)
        {
            ii++;
            zt[ii]=a[j];
            for(int k=1;k<ii;k++)
            {
                if(zt[k]==a[j])
                {
                    ii=k;
                }
            }
        }
        for(int j=1;j<=ii;j++)
        {
            ans[zt[j]]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        if(i==1) cout<<ans[i];
        else cout<<" "<<ans[i];
    }
    return 0;
}
