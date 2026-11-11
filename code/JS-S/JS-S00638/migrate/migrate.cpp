#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5005;

int n,T,c;
ll cnt[N][N],d,pre[N],x[N];

void dfs(int dep,int s)
{
    cnt[dep][s]++;
    if(dep==n) return;
    for(int i=dep+1;i<=n;i++)
        if(pre[i]-pre[dep]<=d)
            dfs(i,s+1);
        else return ;
}
ll ans;

int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0),cout.tie(0),ios::sync_with_stdio(0);
    cin>>c>>T;
    while(T--)
    {
        cin>>n>>d; ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        for(int i=2;i<=n;i++) pre[i]=pre[i-1]+x[i]-x[i-1];
        for(int i=1;i<n;i++)
        {
            dfs(i,0);
            for(int j=i+1;j<=n;j++)
            {
                for(int k=1;k<=j-i;k++)
                {
                    if(cnt[j][k])
                    {
                        if(cnt[j][k]==2) ans++;
                        break;
                    }
                }
            }
            memset(cnt,0,sizeof(cnt));
        }
        cout<<ans<<endl;
    }
    return 0;
}
