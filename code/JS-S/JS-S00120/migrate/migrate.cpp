#include <bits/stdc++.h>
#define int long long

using namespace std;

int read()
{
    int tot=0,f=1;
    char ch=getchar();
    while(ch!='-'&&(ch>'9'||ch<'0'))
        ch=getchar();
    if(ch=='-')
        f=-1,ch=getchar();
    while(ch>='0'&&ch<='9')
        tot=tot*10+(ch-'0'),ch=getchar();
    return tot*f;
}

const int maxn=2e6+10;
int c,T,n,d,x[maxn];

const int inf=1e18;

bool check(int u,int v)
{
    vector <int> cnt(n+1,0);//count
    vector <int> dist(n+1,inf);
    queue <int> q;//bfs
    q.push(u);
    cnt[u]=1;
    dist[u]=0;
    while(!q.empty())
    {
        int fr=q.front();
        q.pop();
        int pos=fr+1;
        while(pos<=v&&x[pos]-x[fr]<=d)
        {
            if(dist[pos]>dist[fr]+1)
            {
                dist[pos]=dist[fr]+1;
                cnt[pos]=cnt[fr];
                q.push(pos);
            }
            else
                if(dist[pos]==dist[fr]+1)
                {
                    cnt[pos]+=cnt[fr];
                    //q.push(pos);
                }
            pos++;
        }
    }
    if(cnt[v]==2)
        return 1;
    return 0;
}

void solve()
{
    n=read(),d=read();
    for(int i=1;i<=n;i++)
        x[i]=read();
    int ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+2;j<=n;j++)
            if(check(i,j))
                ans++;
    printf("%lld\n",ans);
    return ;
}


signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),T=read();
    while(T--)
        solve();
    return 0;
}
