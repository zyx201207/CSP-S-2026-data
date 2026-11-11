#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        bool f[300005]={};
        for(int j=i;j<=n;j++)
        {
            f[a[j]]=1;
            for(int k=i;k<j;k++)
            {
                if(a[k]==a[j])
                {
                    for(int q=k;q<j;q++)f[a[q]]=0;
                }
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(f[j]==1)ans[j]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
