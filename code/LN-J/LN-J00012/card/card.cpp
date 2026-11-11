#include<bits/stdc++.h>
using namespace std;
int a[500005],cnt[500005],q[50005];
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
    int x=1;
    for(int i=1;i<=n;i++)
    {
        int l=1,r=1;
        for(int j=x;j<=n;j++)
        {
            for(int k=l;k<=r;k++)
            {
                if(q[k]==a[j])
                {
                    r=k-1;
                    break;
                }
            }
            q[++r]=a[j];
        }
        for(int j=l;j<=r;j++)
        {
            cnt[q[j]]++;
        }
        x++;
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}
