#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    scanf("%d%d",&n,&m);
    bool f=1;
    int cnt=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int id=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>a[i+1]&&i!=n) f=0;
        if(a[i]!=a[i+1])
        {
            id++;
            sum[id]=sum[id-1]+cnt;
            cnt=1;
        }
        else
        {
            cnt++;
        }
    }
    if(f)
    {
        for(int i=1;i<=m;i++)
            cout<<sum[i]<<" ";
        return 0;
    }
    if(m==2)
    {
        int ans1=0,ans2=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1||a[n]==1) ans1++;
            if(a[i]==2||a[n]==2) ans2++;
        }
        cout<<ans1<<" "<<ans2;
    }
    if(m==1) cout<<n;
    return 0;
}
