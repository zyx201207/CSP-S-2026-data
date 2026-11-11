#include<bits/stdc++.h>
//#define int long long
#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

const int N=505,M=5e5+100,K=1010;

int c,n,m,d,q;
int w[M],k[M];
vector<pair<int,int> > vec[N];
int f[K][K];

namespace WORK1{
    void solve()
    {
        memset(f,0x3f,sizeof f);
        for(int i=1;i<=m;i++)
            f[i][i]=0;
        for(int i=1;i<=n;i++)
        {
            if(k[i]==1) continue;
            auto t1=vec[i][0],t2=vec[i][1];
            f[t1.fi][t2.fi]=f[t2.fi][t1.fi]=t1.se+t2.se;
        }

        //for(int T=1;T<=3;T++)
            for(int k=1;k<=m;k++)
                for(int i=1;i<=m;i++)
                    for(int j=1;j<=m;j++)
                        f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

        while(q--)
        {
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+f[x][y]<<endl;
        }
    }
}

namespace WORK2{
    int t[N],idx;

    void solve()
    {
        idx=m;
        memset(f,0x3f,sizeof f);
        for(int i=1;i<=N-10;i++)
            f[i][i]=0;

        for(int i=1;i<=n;i++)
        {
            auto t0=vec[i][0];
            for(auto t:vec[i])
            {
                idx++;
                f[idx][t.fi]=f[t.fi][idx]=t.se;
                if(t0==t)   continue;
                f[idx][idx-1]=f[idx-1][idx]=0;
                //cout<<f[idx][t.fi]<<" ";
            }
           // cout<<endl;
        }

        for(int k=1;k<=idx;k++)
            for(int i=1;i<=idx;i++)
                for(int j=1;j<=idx;j++)
                    f[i][j]=min(f[i][j],f[i][k]+f[k][j]);

        while(q--)
        {
            int x,y;
            cin>>x>>y;
            cout<<w[x]+w[y]+f[x][y]<<endl;
        }
    }
}

namespace WORK3{
    int sg[M];
    int v[M][3];

    void solve()
    {
        for(int i=1;i<=n;i++)
        {
            for(auto t:vec[i])
            {
                sg[t.fi]+=i;
                v[t.fi][i]=t.se;
            }
        }

        int res=0x3f3f3f3f;

        for(int i=1;i<=m;i++)
            if(sg[i]==3)
                res=min(res,v[i][1]+v[i][2]);

        while(q--)
        {
            int x,y;
            cin>>x>>y;
            if(sg[x]==sg[y])    cout<<w[x]+w[y]+v[x][sg[x]]+v[y][sg[y]]<<endl;
            else cout<<w[x]+w[y]+v[x][sg[x]]+v[y][sg[y]]+res<<endl;
        }
    }
}

using namespace WORK1;
using namespace WORK2;
using namespace WORK3;

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)   cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1,p,q;j<=k[i];j++)
        {
             cin>>p>>q;
             vec[i].pb(mp(p,q));
        }
    }
    if(c<=11 && c>=7)  WORK1::solve();
    else if(c<=6) WORK2::solve();
    else  WORK3::solve();
    return 0;
}
