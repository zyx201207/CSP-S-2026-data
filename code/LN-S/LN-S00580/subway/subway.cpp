#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
const int N=5e5+5;

int n,m,d,q,C;
int w[N];
map<pii,ll>mp;
int line[N*21];//line[i]表示编号为i的点所在的航线
ll tot;
ll get(int x,int u)//表示x线路上，u地铁站的全局编号
{
    if(mp[pii(x,u)]!=0)return mp[pii(x,u)];
    else
    {
        return mp[pii(x,u)]=++tot;
    }
}
ll dis[510][510];
vector<pll>g[N];
vector<int>c[N];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>C>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
        for(int j=1;j<=m;j++)dis[i][j]=1e18;
        dis[i][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a;ll t;
            cin>>a>>t;
            c[a].push_back(i);
            ll getia=get(i,a),get0a=get(0,a);
            line[getia]=i;
            g[get0a].push_back({getia,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(pll p:g[get(0,i)])
        {
            for(pll q:g[get(0,i)])
            {
                ll j=p.first,k=q.first,t1=p.second,t2=q.second;
                if(j==k)continue;
                dis[line[j]][line[k]]=dis[line[k]][line[j]]=min(dis[line[j]][line[k]],t1+t2);
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(i==j)continue;
                ll nw=dis[i][k]+dis[k][j];
                if(nw<dis[i][j])
                {
                    dis[i][j]=nw;
                }
            }
        }
    }
    cout<<q<<"\n";
    while(q--)
    {
        ll ans=9e18;
        int a,b;
        cin>>a>>b;
        for(int i:c[a])
        {
            for(int j:c[b])
            {
                //cout<<i<<" "<<j<<' '<<dis[i][j]<<'\n';
                ll t1=0LL,t2=0LL;
                for(pll p:g[get(0,a)])
                {
                    if(p.first==get(i,a))
                    {
                        t1=p.second;
                        break;
                    }
                }
                for(pll p:g[get(0,b)])
                {
                    if(p.first==get(j,b))
                    {
                        t2=p.second;
                        break;
                    }
                }
                ans=min(ans,dis[i][j]+t1+t2+w[a]+w[b]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

/*
求你了一定要AC喵
已经无能为力了喵
红紫黑黄的不要喵
芙兰朵露脚香香喵
*/
