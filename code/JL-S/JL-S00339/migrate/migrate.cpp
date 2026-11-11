#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>PII;
const int N=2e6+10;
int c,t;
ll n,d;
ll x[N];
int h[N],e[N],ne[N],idx;
int dist[N],cnt[N];
bool st[N];
void add(int a,int b)
{
    e[idx]=b;ne[idx]=h[a];h[a]=idx++;
}
void dijkstra(int s)
{
    for(int i=0;i<=n;i++)
        dist[i]=0x3f3f3f3f,st[i]=false,cnt[i]=0;
    priority_queue<PII,vector<PII>,greater<PII> >q;
    q.push({0,s});
    dist[s]=0;cnt[s]=1;
    while(q.size())
    {
        PII t=q.top();q.pop();
        int ver=t.second;
        if(st[ver])continue;
        st[ver]=true;
        for(int i=h[ver];i!=-1;i=ne[i])
        {
            int j=e[i];
            if(dist[j]>dist[ver]+1)
            {
                dist[j]=dist[ver]+1;cnt[j]=cnt[ver];
                q.push({dist[j],j});
            }
            else if(dist[j]==dist[ver]+1)cnt[j]+=cnt[ver];
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>c>>t;
    memset(h,-1,sizeof h);
    while(t--)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>x[i];
        if(c==11||c==12)
        {
            int ans=0;
            ll cha=abs(x[1]-x[2]);
            ll num=n-3;
            //cout<<num<<endl;
            if(cha*2<=d&&d<cha*3)cout<<num<<endl;
            else cout<<0<<endl;
            continue;
        }
        for(int i=1;i<=n;i++)
            for(int j=i+1;j<=n;j++)
                if(abs(x[i]-x[j])<=d)
                    add(i,j),add(j,i);
        ll res=0;
        for(int i=1;i<=n;i++)
        {
            dijkstra(i);
            for(int j=i+1;j<=n;j++)
                if(cnt[j]==2)
                    res++;
        }
        cout<<res<<endl;
        for(int i=0;i<=n;i++)h[i]=-1,e[i]=ne[i]=0;idx=0;
    }
    return 0;
}
