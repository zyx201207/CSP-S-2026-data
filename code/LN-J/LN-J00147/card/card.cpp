#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long num[500010],vis[500010],inq[500010],a[500010];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++)
    {
        for(long long i=1;i<=m;i++)
        {
            inq[i]=-1;
        }
        for(long long j=i;j<=n;j++)
        {
            if(inq[a[j]]!=-1)
            {
                for(long long k=inq[a[j]];k<j;k++)
                {
                    inq[a[k]]=-1;
                }
                inq[a[j]]=j;
            }
            else
            {
                inq[a[j]]=j;
            }
        }
        for(long long j=1;j<=m;j++)
        {
            if(inq[j]!=-1)
            {
                num[j]++;
            }
        }
    }
    for(long long i=1;i<=m;i++)
    {
        cout<<num[i]<<" ";
    }
    return 0;
}
