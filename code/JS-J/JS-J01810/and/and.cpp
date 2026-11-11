#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[210000],dp[210000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i = 1;i <= n;i++)
    {
        int t;
        scanf("%d",&t);
        a[i] = t;
    }
    for(int i = 1;i <= n;i++)
    {
        for(int j = m;j >= 1;j--)
        {
            if(j == 1)
            {
                dp[j] = max(a[i],dp[j]);
            }
            else
            {
                dp[j] = max(dp[j-1]&a[i],dp[j]);
            }
        }
    }
    printf("%lld\n",dp[m]);
    return 0;
}
