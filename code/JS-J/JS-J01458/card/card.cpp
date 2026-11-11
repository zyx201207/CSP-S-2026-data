#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ans[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            if(j!=i)
            {
                if(a[j]!=a[j-1])
                {
                    ans[a[j-1]]++;
                }
            }
        }
        ans[a[n]]++;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}
