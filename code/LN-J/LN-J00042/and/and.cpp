#include<bits/stdc++.h>
using namespace std;
int a[200001],x[200001][31],sum[31],in[200001];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        for(int j=30;j>=0;j--)
        {
            if(a[i]>=(1<<j)){x[i][j]=1;a[i]-=(1<<j);sum[j]++;}
            else x[i][j]=0;
        }
        in[i]=1;
    }
    long long ans=0;
    for(int j=30;j>=0;j--)
    {
        if(sum[j]>=m)
        {
            ans+=(1<<j);
            for(int i=1;i<=n;i++)
            {
                if(!x[i][j]&&in[i]==1)
                {
                    for(int k=j;k>=0;k--)
                    {
                        if(x[i][k])sum[k]--;
                    }
                    in[i]=0;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

