#include<bits/stdc++.h>
using namespace std;
long long a[500001],ans[300001],b[300001],c,m,n;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i];
    for(long long i=1;i<=n;i++)
    {
        for(long long j=i;j<=n;j++)
        {
            for(long long k=1;k<=c;k++)if(ans[k]==a[j]){c=k-1;break;}
            ans[++c]=a[j];
        }
        for(long long j=1;j<=c;j++)b[ans[j]]++;
        memset(ans,0,sizeof(ans));
        c=0;
    }
    for(long long i=1;i<=m;i++)cout<<b[i]<<(i==n?"":" ");
    return 0;
}
