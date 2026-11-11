#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int ans;
int a[200005];
bool er[200005][35];
bool ifqudiao[2000005];
int ssum(int k)
{
    int sssum=0;
    for (int i=1;i<=n;i++)
    {
        if (ifqudiao[i])
        {
            continue;
        }
        else
        {
            if (er[i][k]==1)
            {
                sssum++;
            }
        }
    }
    return sssum;
}
void chuli(int q)
{
    if (ssum(q)>=m)
    {
        for (int i=1;i<=n;i++)
        {
            if (er[i][q]==0)
            {
                ifqudiao[i]=1;
            }
        }
        ans+=pow(2,32-q);
    }
}
void calc(int t)
{
    int n=a[t];
    int k=32;
    while(n!=0)
    {
        if (n%2==0)
        {
            er[t][k]=0;
        }
        else
        {
            er[t][k]=1;
        }
        n/=2;
        k--;
    }
}
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        calc(i);
    }
    for (int i=0;i<=32;i++)
    {
        chuli(i);
    }
    cout<<ans<<endl;
    return 0;
}
