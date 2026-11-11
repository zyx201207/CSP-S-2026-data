#include<bits/stdc++.h>
using namespace std;
int n,m,maxo=0;
const int maxn=pow(2,30);
int a[2000005];
int ans=maxn;
bool dp[2000005][35];
int r[2000005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        int t=a[i];
        int o=0;
        while(t)
        {
            dp[i][o++]=t%2;
            t/=2;
        }
        maxo=max(maxo,o-1);
    }
    for(int i=maxo;i>=0;i--)
    {
        int k=0;
        for(int j=1;j<=n;j++)
        {
            if(dp[j][i]==1)
            {
                r[k]=j;k++;
            }

        }
        if(k>=m)
        {
            for(int j=1;j<=k;j++)
                ans&=r[j];
        }
    }

    cout<<ans;
    return 0;
}
