#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second

const ll N=505,M=5e5+5;
const ll inf=1e15;
const ll mod=1e9+7;

ll _;
ll ID,n,m,d,q;
ll w[M]; //kou->ting
vector<pair<ll,ll> > e[N]; // tai->ting
vector<ll> to[M];
ll dis[N][N];
// bitset<M> bt[N];
ll ff[N][N];
map<ll,ll> ds[M];

void bfs(ll s)
{
    memset(dis[s],0x3f,sizeof dis[s]);
    queue<ll> q;
    q.push(s);
    dis[s][s]=0;
    while(!q.empty())
    {
        ll x=q.front();
        // cerr<<x<<"??\n";
        q.pop();
        for(auto i:e[x])
        {
            ll y=i.fi,v=i.se;
            if(dis[s][y]>dis[s][x]+v)
            {
                dis[s][y]=dis[s][x]+v;
                q.push(y);
            }
        }
    }
}

void solve()
{ 
    cin>>ID>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++)
    {
        ll k;
        cin>>k;
        for(ll j=1;j<=k;j++)
        {
            ll x,y;
            cin>>x>>y;
            // bt[i][x]=1;
            to[x].push_back(i);
            ds[x][i]=y;
        }
    }
    // cerr<<(int)bt[15][127]<<" "<<bt[14][127]<<"???\n";;
    memset(ff,0x3f,sizeof ff);
    for(int i=1;i<=m;i++)
    {
        for(auto x:to[i])
        {
            for(auto y:to[i])
            {
                if(x>=y) continue;
                ff[x][y]=min(ff[x][y],ds[i][x]+ds[i][y]);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(ff[i][j]>=inf) continue;
            e[i].push_back({j,ff[i][j]});
            e[j].push_back({i,ff[i][j]});
        }
    }


    // for(ll i=1;i<=n;i++)
    // {
    //     for(ll j=i+1;j<=n;j++)
    //     {
    //         // cerr<<i<<" "<<j<<"??\n";
    //         bitset<M> tmp=bt[i]&bt[j];
    //         // cerr<<i<<" "<<j<<" "<<tmp.count()<<"why???\n";
    //         ll mn=inf,mnp=0;
    //         // cerr<<tmp._Find_first()<<"nani?\n";
    //         for(auto k=tmp._Find_first();k<=m;k=tmp._Find_next(k+1))
    //         {
    //             // cerr<<k<<"??\n";
    //             ll val=ds[k][i]+ds[k][j];
    //             if(val<mn)
    //             {
    //                 // cerr<<k<<"???\n";
    //                 mn=val,mnp=k;
    //             }
    //         }
    //         if(mnp)
    //         {
    //             e[i].push_back({j,mn});
    //             e[j].push_back({i,mn});
    //             // cerr<<i<<" "<<j<<" ok: "<<mn<<"??\n";
    //         }
    //     }
    // }
    // cerr<<"here??\n";
    
    for(ll i=1;i<=n;i++)
    {
        bfs(i);
    }
    // cerr<<"or??\n";

    // cerr<<"ok input?\n";
    while(q--)
    {
        ll x,y;
        cin>>x>>y;
        if(x==y)
        {
            cout<<"0\n";
            continue;
        }
        ll ans=inf;
        for(auto i:to[x])
        {
            for(auto j:to[y])
            {
                if(i==j)
                {
                    ans=min(ans,w[x]+w[y]+ds[x][i]+ds[y][i]);
                    continue;
                }
                // cerr<<x<<" "<<y<<" "<<i<<" "<<j<<" "<<w[x]<<" "<<w[y]<<" "<<ds[i][x]<<" "<<ds[j][y]<<" "<<dis[i][j]<<" check\n"; 
                ans=min(ans,w[x]+w[y]+ds[x][i]+ds[y][j]+dis[i][j]);
            }
        }
        cout<<ans<<"\n";
    }
     
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    // cin>>_;
    _=1;
    while(_--)
    {
        solve();
    }

    return 0;
}
/*
g++ subway.cpp -o subway -std=c++14 -O2
/usr/bin/time -v ./subway
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
