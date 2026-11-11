#include <iostream>
#include <unordered_map>
using namespace std;
const int N=5e5+10;
const int M=3e5+10;
int n,m,a[N],ans[M];

unordered_map<int,int> mp;

int main()
{
    //freopen("card.in","r",stdin);
    //freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }

    int tt=n;
    for (int i=1;i<=n;i++)
    {
        for (int j=i;j<=n;j++)
        {
            mp[a[j]]++;
            tt--;
            if (mp[a[j]]>=2)
            {
                mp[a[j]]=1;
            }
        }
        for (int j=i;j<=n;j++)
        {
            unordered_map<int,bool> flag(0);
            if (mp[a[j]]>=1&&flag[a[j]]==0)
            {
                ans[a[j]]++;
                flag[a[j]]=1;
            }
        }
        for (int j=1;j<=n;j++)
        {
            mp[a[j]]=0;
        }
    }

    for (int i=1;i<=m;i++)
    {
        printf("%d ",ans[i]);
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}
