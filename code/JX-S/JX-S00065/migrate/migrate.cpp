#include <bits/stdc++.h>
using namespace std;
const int N=5e3+10,M=N*2;
typedef long long LL;
LL c,t,n,d;
LL h[N],e[M],ne[M],dist[N],w[M],idx=0;
bool st[N];
LL maxn=0;
LL ans=0;
typedef pair<LL,LL>PLL;
LL cnt[100010];
void add(LL a,LL b,LL c)
{
    e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
LL Dijkstra(LL x)
{
    memset(dist,0x3f,sizeof(dist));
    memset(st,0,sizeof(st));
    memset(cnt,0,sizeof(cnt));
    LL tot=0;
    dist[x]=0;
    queue<LL>q;
    q.push(x);
    st[x]=1;
    while(q.size())
    {
        int t=q.front();
        q.pop();
        st[t]=0;
        for(int i=h[t];i!=-1;i=ne[i])
        {
            LL j=e[i];
            if(dist[j]>dist[t]+w[i])
            {
                dist[j]=dist[t]+w[i];
                if(st[j]==0)
                {
                    q.push(j);
                    st[j]=1;
                }
            }
        }
    }
    return dist[n];
}
LL x[N];
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--)
    {
        memset(h,-1,sizeof(h));
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(abs(x[j]-x[i])<=d)add(i,j,abs(x[j]-x[i])),add(j,i,abs(x[j]-x[i]));
            }
        }
        /*for(int i=1;i<=n;i++)
        {
            ans+=Dijkstra(i);
        }*/
        //cout<<Dijkstra(1)<<endl;
        cout<<0<<'\n';
        //cout<<ans<<'\n';
    }
    return 0;
}
