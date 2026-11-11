#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    int sum[m+5],sum2[m+5];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum[a[i]]++;
        sum2[a[i]]++;
    }
    a[0]=-1;
    for(int k=1;k<=n;k++)
    {
        sum2[a[k-1]]--;
        for(int i=k;i<=n;i++)
        {
            if(sum[a[i]]==1)
            {
                ans[a[i]]++;
                continue;
            }
            for(int j=i+1;j<=n;j++)
            {
                sum[a[j]]--;
                if(a[i]==a[j])
                {
                    i=j-1;
                    break;
                }
            }
        }
        for(int i=k;i<=n;i++)
        {
            sum[a[i]]=sum2[a[i]];
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
}
