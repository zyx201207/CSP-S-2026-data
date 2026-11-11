#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+5;
int c,t,n,in[N],b[N],sum[N],route[N];
ll x[N],d;
vector<int> edges[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        ll ans=0;
        for(int i=1;i<=n;i++) cin>>x[i];
        if(c==11||c==12)
        {
            cout<<n-1-(d/(x[2]-x[1]))<<'\n';
            continue;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if((x[i]+d)>=x[j])
                {
                    edges[i].push_back(j);
                    in[j]++;
                }
            }
        }
        queue<int> q;
        for(int i=1;i<=n;i++)
        {
            while(q.size()) q.pop();
            q.push(i);
            for(int j=1;j<=n;j++)
            {
                b[j]=in[j];
                route[j]=-1;
                sum[j]=0;
            }
            route[i]=0;
            sum[i]=1;
            while(q.size())
            {
                int u=q.front();
                q.pop();
                int len=edges[u].size();
                for(int j=0;j<len;j++)
                {
                    int v=edges[u][j];
                    b[v]--;
                    if(route[v]==-1||route[u]+1<route[v]) route[v]=route[u]+1,sum[v]=sum[u];
                    else if(route[u]+1==route[v]) sum[v]+=sum[u];
                    if(b[v]==0) q.push(v);
                }
            }
            for(int j=1;j<=n;j++) ans+=(sum[j]==2);
            for(int j=i+1;j<=n;j++)
            {
                if((x[i]+d)>=x[j])
                in[j]--;
            }
        }
        cout<<ans<<'\n';
        for(int i=0;i<=n+5;i++)
        {
            x[i]=0;
            edges[i].clear();
            in[i]=0;
            b[i]=0;
        }
    }
    return 0;
}
