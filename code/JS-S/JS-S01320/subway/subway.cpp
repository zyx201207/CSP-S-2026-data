#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int N = 5e5+10;
ll c,n,m,d,q,w[N],k,dist[1005][1005];
struct node
{
    ll a,t;
};
vector<node>b[505],s[1005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dist,0x3f,sizeof(dist));
    //cin >> c >> n >> m >> d >> q;
    scanf("%lld %lld %lld %lld %lld",&c,&n,&m,&d,&q);
    for(int i =1; i<=m; i++)
    {
        //cin >> w[i];
        scanf("%lld",&w[i]);
    }
    for(int i =1; i<=n; i++)
    {
        scanf("%lld",&k);
        for(int j =1; j<=k; j++)
        {
            ll x,y;
            //cin >> x >> y;
            scanf("%lld %lld",&x,&y);
            b[i].push_back({x,y});
            s[x].push_back({i,y});
        }
    }
    for(int i = 1; i<=m; i++)
    {
        for(auto v:s[i])
        {
            for(auto v1:b[v.a])
            {
                if(dist[i][v1.a] > v1.t + v.t)
                {
                    dist[i][v1.a] = v1.t + v.t;
                }
            }
        }
    }
    for(int i =1; i<=m; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            for(int k = 1; k<=m; k++)
            {
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
    while(q--)
    {
        ll x,y;
        scanf("%lld %lld",&x,&y);
        ll ans = dist[x][y] + w[x] + w[y];
        printf("%lld\n",ans);
    }
}
