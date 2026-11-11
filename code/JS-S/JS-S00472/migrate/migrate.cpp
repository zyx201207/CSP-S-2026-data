#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int M=2e6+10;
int c,t;
int n;
ll d;
ll x[M];
int dist(int u,int v)
{
    int pos=u;
    int res=0;
    while(pos<v)
    {
        int cnt=lower_bound(x+u,x+n+1,x[pos]+d)-x;
        if(cnt==pos) return -1e18-10;
        pos=cnt;
        res++;
    }
    return res;
}
void dfs(int tar,int u,int ed,int &res,int cnt)
{
    if(cnt==tar && u==ed)
    {
        res++;
        return ;
    }
    if(cnt>=tar) return ;
    for(int i=u+1;i<=n;++i)
    {
        if(x[i]>x[u]+d) break;
        dfs(tar,i,ed,res,cnt+1);
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;++i) cin>>x[i];
        int res=0;
        for(int i=1;i<=n;++i)
        {
            for(int j=i+1;j<=n;++j)
            {
                int low=dist(i,j);
                int ans=0;
                dfs(low,i,j,ans,0);
                if(ans==2) res++;
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
