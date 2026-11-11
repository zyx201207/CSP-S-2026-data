#include<bits/stdc++.h>
using namespace std;
int n,d;
int x[2000005],cnt[2000005];
void DFS(int i)
{
    if(i==n) return ;
    for(int j=i+1;j<=n;j++)
    {
        if(x[j]-x[i]<=d)
        {
            cnt[j]++;
            DFS(j);
        }
        else
        {
            break;
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int n,d;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        for(int i=1;i<=n;i++)
        {
            memset(cnt,0,sizeof cnt);
            DFS(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            ans+=cnt[i];
        }
        cout<<ans<<"\n";
    }
    return 0;
}
