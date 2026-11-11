#include<bits/stdc++.h>
using namespace std;
int m,n,ans = 0;
int a[20005];
bool b[20005];
void dg(int dep,int sum)
{
    if(dep > n)
    {
        ans = max(ans,sum);
        return;
    }
    for(int i = 1;i <= m;i++)
    {
        if(sum & a[i] > ans && b[i] == 0)
        {
            b[i] = 1;
            dg(dep + 1,a[i] & sum);
            b[i] = 0;
        }
    }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i = 1;i <= m;i++)
    {
        scanf("%d",&a[i]);
    }
    for(int i = 1;i <= m;i++)
    {
        b[i] = 1;
        dg(2,a[i]);
        b[i] = 0;
    }
    printf("%d",ans);
    return 0;
}
