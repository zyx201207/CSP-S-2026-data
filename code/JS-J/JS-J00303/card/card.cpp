#include<bits/stdc++.h>
using namespace std;
int a[500005],last[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,k=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]) k=1;
    }
    if(k==0)
    {
        for(int i=1;i<=n;i++)
        {
            last[a[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            cout<<last[i]<<" ";
        }
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            k=i;
            for(int j=i;j<=n;j++)
            {
                for(int s=j-1;s>=k;s--)
                {
                    if(a[s]==a[j])
                    {
                        k=j;
                        break;
                    }
                }
            }
            for(int j=k;j<=n;j++)
            {
                last[a[j]]++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            cout<<last[i]<<" ";
        }
    }
    return 0;
}
