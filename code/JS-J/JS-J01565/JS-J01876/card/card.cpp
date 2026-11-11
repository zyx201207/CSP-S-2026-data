#include <bits/stdc++.h>
using namespace std;
int n,m,card[500005],num[300005],sum[300005],siz;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>card[i];
    for(int t=1;t<=n;t++)
    {
        memset(num,0,sizeof num);
        for(int i=t;i<=n;i++)
        {
            if(num[card[i]]==0)
                num[card[i]]=i;
            else
            {
                for(int j=1;j<=m;j++)
                {
                    if(num[j]>=num[card[i]]&&num[j]<=i-1)
                        num[card[j]]=0;
                }

                num[card[i]]=i;
            }
        }
        for(int i=1;i<=m;i++)
        {
            sum[i]+=(num[i]>0);
        }
    }
    for(int i=1;i<=m;i++)
        cout<<sum[i]<<" ";
    return 0;
}
