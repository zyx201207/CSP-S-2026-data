#include <bits/stdc++.h>
using namespace std;
int a[200005];
int zhuomian[200005];
int sum[200005];
int maxzhuo=0;
int n,m;
void put(int j)
{
    bool k=0;
    int h=0;
    for (int i=1;i<=maxzhuo;i++)
    {
        if (zhuomian[i]==a[j])
        {
            k=1;h=i;
        }
    }
    if (k==0)
    {
        maxzhuo++;
        zhuomian[maxzhuo]=a[j];
    }
    else
    {
        maxzhuo=h;
    }
}
bool calc(int i)
{
    for (int j=i;j<=n;j++)
    {
        put(j);
    }
    for (int j=1;j<=maxzhuo;j++)
    {
        sum[zhuomian[j]]++;
    }
    return 0;
}
int ans=0;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        calc(i);
        memset(zhuomian,0,sizeof(zhuomian));
    }
    for (int i=1;i<=m;i++)
    {
        cout<<sum[i]<<" ";
    }
    return 0;
}
