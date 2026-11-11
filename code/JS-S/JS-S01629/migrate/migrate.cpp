#include <bits/stdc++.h>
using namespace std;
long long c,t;
long long a[2000002];
vector<long long>up[2000002];
vector<long long>down[2000002];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--)
    {
        long long n,d,ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++)
        {
            up[i].clear();
            down[i].clear();
            scanf("%lld",&a[i]);
            for(int j=1;j<i;j++)
            {
                if(a[i]-a[j]<=d)
                {
                    up[i].push_back(j);
                    down[j].push_back(i);
                }
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                long long l=0,r=0,sum=0;
                while(true)
                {
                    if(r>=up[j].size()||l>=down[i].size())
                    {
                        break;
                    }
                    if(up[j][r]<down[i][l])
                    {
                        r++;
                    }
                    if(up[j][r]>down[i][l])
                    {
                        l++;
                    }

                    if(up[j][r]==down[i][l])
                    {
                        sum++;
                        r++;
                        l++;
                    }
                    if(sum>2)
                    {
                        break;
                    }
                }
                if(sum==2)
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
