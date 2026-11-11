#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=505;
vector<pair<int,int> > e[N];
int k[M][N];
int p[M][N];
struct st
{
    int u;
    long long s;
    int wy;
    long long cst;
    bool operator<(const st& b) const
    {
        return s<b.s;
    }
};
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,n,m,q,i,j,d,l,x,y;
    cin>>c>>m>>n>>d>>q;
    int a[n+2];
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=m;i++)
    {
        cin>>l;
        for(j=1;j<=l;j++)
        {
            cin>>p[i][j]>>k[i][j];
            if(j>1)
            {
                //cout<<" "<<p[i][j-1]<<" "<<p[i][j]<<" "<<i<<" "<<j<<"\n";
                e[p[i][j-1]].push_back({i,j});
            }
        }
    }
    for(i=1;i<=q;i++)
    {
        cin>>x>>y;
        priority_queue<st> q;
        q.push({x,0,-1,0});
        long long u,w,ans=-1,h,wy,cst;
        while(!q.empty())
        {
            u=q.top().u;
            w=q.top().s;
            wy=q.top().wy;
            cst=q.top().cst;
            //cout<<u<<" "<<w<<" "<<wy<<" "<<cst<<" \n";
            q.pop();
            if(u==y&&(ans>w||ans==-1)) ans=w;
            for(auto v:e[u])
            {
                if(v.first==wy) h=w-cst+k[v.first][v.second];
                else h=w+k[v.first][v.second]+k[v.first][v.second-1];
                //cout<<u<<" "<<v.first<<" "<<v.second<<" "<<h<<" "<<w<<" "<<k[v.first][v.second]<<" "<<k[v.first][v.second-1]<<"\n";
                 if(h-k[v.first][v.second]<ans||ans==-1)   q.push({p[v.first][v.second],h,v.first,k[v.first][v.second]});
            }
        }
        cout<<(ans+a[x]+a[y])<<"\n";
    }
    return 0;
}
