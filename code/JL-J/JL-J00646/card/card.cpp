#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int b[1000000];
int ans[1000000];
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
        for(int j=1;j<=n;j++)
        {
            b[a[j]]=0;
        }
        for(int j=i;j<=n;j++)
        {
            b[a[j]]=1;
            int p;
            for(int k=i;k<j;k++)
            {
                if(a[k]==a[j])
                {
                    p=k;
                    break;
                }
            }
            for(int s=p;s<j;s++)
            {
                b[a[s]]=0;
            }
        }
        for(int j=i;j<=n;j++)
        {
            if(b[a[j]]==1)
            {
                ans[a[j]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[m]<<' ';
    }
}
