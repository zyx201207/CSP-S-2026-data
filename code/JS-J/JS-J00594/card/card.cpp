#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[3005],sum,b[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        sum=i;
        for(int j=i;j<=n;j++)
        {
            ans[a[j]]++;
            if(ans[a[j]]>1)
            {
                sum=j;
                for(int k=1;k<=m;k++)ans[k]=0;
                ans[a[j]]=1;
            }
        }
        for(int j=sum;j<=n;j++)
        {
            b[a[j]]++;
        }
        for(int j=1;j<=n;j++)
        {
            ans[j]=0;
        }
    }
    for(int i=1;i<=m;i++)cout<<b[i]<<' ';
}
