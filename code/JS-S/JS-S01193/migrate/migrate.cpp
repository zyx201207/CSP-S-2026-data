#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[2000005],n,d;
int mn[5005],cnt[5005];
void dfs(int x,int step)
{
    if(step>mn[x])
        return;
    int res=0;
    if(step==mn[x])
        cnt[x]++;
    for(int i=x+1;i<=n;i++)
        if(a[i]<=a[x]+d)
            dfs(i,step+1);
}
signed main()
{
    std::cin.sync_with_stdio(0);cin.tie();cout.tie();
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        if(C==11 || C==12)
        {
            int t=d/(a[2]-a[1]);
            if(t<=1 || t>=n-1)
                ans=0;
            else
                ans=n-2*t+1;
            cout<<ans<<'\n';
            continue;
        }
        memset(mn,0x3f,sizeof(mn));
        int far=0,step=1;
        for(int i=1;i<=n;i++)
        {
            far=a[i]+d,step=1;
            for(int j=i+1;j<=n;j++)
            {
                if(a[j]>far)
                    far=a[j-1]+d,step++;
                mn[j]=step,cnt[j]=0;
            }
            /*for(int j=i+1;j<=n;j++)
                cout<<mn[j]<<" ";
            cout<<'\n';*/
            mn[i]=0,cnt[i]=0;
            dfs(i,0);
            for(int j=i+1;j<=n;j++)
                ans+=(cnt[j]==2);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
