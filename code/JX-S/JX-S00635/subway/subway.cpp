#include<bits/stdc++.h>
using namespace std;
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
struct FSI{
    template<typename T>
    FSI& operator >> (T &res){
        res=0;T f=1;char ch=getchar();
        while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
        while (isdigit(ch)){res=res*10+ch-'0';ch=getchar();}
        res*=f;
        return *this;
    }
}scan;
typedef long long ll;
typedef pair<int,int> pii;
const int N=510,M=5e5+10;
const ll inf=2e18+1000000;
int Case,n,m,d,q,i,j,l,k[N],o,p,ido,idp,sz,x,y,szx,szy;
ll w[M];
vector<int> a[N];
vector<pii> G[M];
vector<ll> t[N];
ll f[N][N],ans;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scan>>Case>>n>>m>>d>>q;
    for (i=1;i<=m;i++) scan>>w[i];
    for (i=1;i<=n;i++)
    {
        scan>>k[i];
        a[i].resize(k[i]+2);
        t[i].resize(k[i]+2);
        for (j=0;j<k[i];j++) scan>>a[i][j]>>t[i][j],G[a[i][j]].push_back({i,j});
    }
    for (i=1;i<=n;i++)
    {
        for (j=1;j<=n;j++) f[i][j]=inf;
        f[i][i]=0;
    }
    for (i=1;i<=m;i++)
    {
        sz=G[i].size();
        for (j=0;j<sz;j++)
        {
            for (l=j+1;l<sz;l++)
            {
                o=G[i][j].first;p=G[i][l].first;
                ido=G[i][j].second;idp=G[i][l].second;
                f[o][p]=min(f[o][p],t[o][ido]+t[p][idp]);
                f[p][o]=f[o][p];
            }
        }
    }
    for (l=1;l<=n;l++)
    {
        for (i=1;i<=n;i++)
        {
            for (j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][l]+f[l][j]);
        }
    }
    while (q--)
    {
        scan>>x>>y;
        szx=G[x].size();szy=G[y].size();
        ans=inf;
        for (i=0;i<szx;i++)
        {
            for (j=0;j<szy;j++)
            {
                o=G[x][i].first;p=G[y][j].first;
                ido=G[x][i].second;idp=G[y][j].second;
                ans=min(ans,w[x]+w[y]+t[o][ido]+t[p][idp]+f[o][p]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}