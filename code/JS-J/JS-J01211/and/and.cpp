#include <iostream>
using namespace std;
const int N=2e5+5;
int n,m,mp[N],maxn=-1,ans=-1;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&mp[i]);
        maxn=max(maxn,mp[i]);
    }
    if (m==1)
    {
        printf("%d",maxn);
    }
    else if (m==2)
    {
        for (int i=1;i<=n;i++)
        {
            for (int j=i;j<=n;j++)
            {
                ans=max(ans,mp[i]&mp[j]);
            }
        }
        printf("%d",ans);
    }
    else if (m==n)
    {
        ans=mp[1];
        for (int i=2;i<=n;i++)
        {
            ans=mp[i]&ans;
        }
        printf("%d",ans);
    }
    else if (m==n-1)
    {
        ans=mp[1];
        for (int i=1;i<=n;i++)
        {
            ans=mp[i]&ans;
        }
        int x=ans;
        for (int i=1;i<=n;i++)
        {
            ans=max(x,(!x)^mp[i]);
        }
        printf("%d",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
