#include <bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define pll pair<ll,ll>
#define pii pair<int,int>
#define fs first
#define sc second
#define all(v) v.begin(),v.end()
#define pb push_back
#define ppb pop_back
using namespace std;
inline void MAX(auto &x,auto y){x=max(x,y);}
inline void MIN(auto &x,auto y){x=min(x,y);}
const int N=1e6+5,inf=1e9;
struct state{int x,y,z;};
vector<state> f[N][2][3];
int lim;
inline state operator+(state A,state B)
{
    state C={-1,min(A.y,B.y+(B.y^inf)),min(A.z+B.z,inf)};
    if(A.y^inf&&~B.x&&A.y+B.x+1<=lim) B.x=-1;
    if(B.y^inf&&~A.x&&A.x+B.y+1<=lim) A.x=-1;
    C.x=max(A.x,B.x+(B.x!=-1));
    return C;
}
int n,m;
vector<int> e[N];
void dfs(int x,int F)
{
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            vector<state>.swap(f[x][i][j]);
    f[x][0][0]={0,-1,0};
    f[x][1][1]={-1,0,1};
    for(auto y:e[x])
    {
        if(y==F) continue;
        dfs(y,x);
        for(int i=0;i<3;i++)
        {

        }
    }
}
bool check(int mid)
{
    lim=mid,dfs(1,0);
    for(int i=0;i<2;i++)
        for(int j=0;j<3;j++)
            if(f[1][i][j].x==-1&&f[1][i][j].z<=m)
                return 1;
    return 0;
}
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        e[i].clear();
    for(int i=1,x,y;i<n;i++)
        cin>>x>>y,e[x].pb(y),e[y].pb(x);
    int l=0,r=n-1,mid,ans=n-1;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid))
            ans=mid,r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<'\n';
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C,T;cin>>C>>T;
    while(T--) solve();
    return 0;
}