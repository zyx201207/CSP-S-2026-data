#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define fi first
#define se second

const ll N=1e5+5;
const ll inf=1e9;
const ll mod=1e9+7;

ll _;
ll n,d;
ll X[N];
ll par[N],dep[N];
ll ans;
vector<ll> e[N];
ll dp[N][3];


void dfs(ll x,ll f)
{
    dep[x]=dep[f]+1;
    sort(e[x].begin(),e[x].end());
    if(!e[x].size())
    {
        dp[x][0]=0;
        dp[x][1]=0;
        return ;
    }
    else if(e[x].size()==1)
    {
        ll y=e[x][0];
        dfs(y,x);
        dp[x][0]+=dp[y][0];
        dp[x][1]+=dp[y][1];
        dp[x][0]++;
    }
    else if(e[x].size()>=2)
    {
        ll y1=e[x][0],y2=e[x][1];
        dfs(y1,x),dfs(y2,x);
        dp[y2][1]+=(e[x].size()-1)*dp[y1][1];
        dp[x][0]+=dp[y1][0],dp[x][1]+=dp[y2][0]+dp[y1][1];
        dp[x][0]+=e[x].size();
    }
}

ll dis(ll x,ll y)
{
    return dep[y]-dep[x];
}

void solve()
{ 
    cin>>n>>d;
    for(ll i=1;i<=n;i++) cin>>X[i];
    for(ll i=1;i<=n;i++)
    {
        e[i].clear();
        dp[i][0]=dp[i][1]=0;
    }
    for(ll i=1;i<=n;i++)
    {
        ll t=upper_bound(X+i,X+n+1,X[i]+d)-X-1;
        if(t!=i)
        {
            par[i]=t;
            e[t].push_back(i);
        }
        dep[i]=0;
    }
    // for(ll i=n;i>=1;i--) 
    // {
    //     cerr<<i<<": ";
    //     for(auto j:e[i])
    //     {
    //         cerr<<j<<" ";
    //     }
    //     cerr<<"\n";
    // }
    for(ll i=n;i>=1;i--)
    {
        if(!dep[i])
        {
            dfs(i,0);
        }
    }
    ans=0;
    for(ll i=1;i<=n;i++) ans+=dp[i][1];
    // for(ll i=1;i<=n;i++) cerr<<dp[i][1]<<" ";
    // cerr<<"\n";
    cout<<ans<<"\n";
    // for(ll i=1;i<=n;i++)
    // {
    //     cout<<L[i]<<" "<<R[i]<<" "<<i<<" !\n";
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>_>>_;
    while(_--)
    {
        solve();
    }

    return 0;
}
/*
g++ migrate.cpp -o migrate -std=c++14 -O2
/usr/bin/time -v ./migrate
*/
