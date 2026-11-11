#include<bits/stdc++.h>
using namespace std;
long long n,m,a[2000005],cnt[2000005],num[2000005];
void DFS(long long x,long long step)
{
    for(long long i=x+1;i<=n;i++)
    {
        if(a[i]-a[x]<=m)
        {
            if(num[i]>step)
            {
                cnt[i]=1;
                num[i]=step;
                DFS(i,step+1);
            }
            else if(num[i]==step)
            {
                cnt[i]++;
                DFS(i,step+1);
            }
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(long long i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        long long ans=0;
        for(long long z=1;z<n;z++)
        {
            for(int i=z;i<=n;i++)
            {
                cnt[i]=0;
                num[i]=2000005;
            }
            DFS(z,1);
            for(long long i=z+1;i<=n;i++)
            {
                if(cnt[i]==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
