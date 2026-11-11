#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
using namespace std;
int c,n,m,d,q;
const int N=5*1e3+1000;
int ll[N][N];
int w[N];
const int M=1e12;
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    int x,y,l,r;
    for(int i=1;i<=1001;i++)
    {
        for(int j=1;j<=1001;j++)
        {
;            ll[i][j]=M;
        }
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&c);
        scanf("%lld",&x);
        scanf("%lld",&l);
        scanf("%lld",&y);
        scanf("%lld",&r);
        ll[x][y]=l+r;
        ll[y][x]=l+r;
    }
    for(int k=1;k<=m;k++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(ll[i][k]+ll[k][j]<ll[i][j])
                {
                    ll[i][j]=ll[i][k]+ll[k][j];
                }

            }
        }
    }
    while(q--)
    {
        cin>>x>>y;
        printf("%lld\n",ll[x][y]+w[x]+w[y]);
    }
}
