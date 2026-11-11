#include <bits/stdc++.h>
using namespace std;
long long n,m,i,j,k,l,c,a[500009],d[509][509],q,x,y,ans;
struct node{
    long long u,v;
};
vector<node>v[501009];
int main(){
    std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>l>>q;
    for(i=1;i<=m;i++)cin>>a[i];
    for(i=1;i<=n;i++){
        cin>>k;
        for(j=1;j<=k;j++){
            cin>>x>>y;
            v[x].push_back({i,y});
        }
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++)if(i!=j)d[i][j]=LONG_LONG_MAX;
    }
    for(i=1;i<=m;i++){
        for(j=0;j<v[i].size();j++)
        for(k=0;k<v[i].size();k++){
            d[v[i][j].u][v[i][k].u]=min(d[v[i][j].u][v[i][k].u],v[i][j].v+v[i][k].v);
        }
    }
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
    for(k=1;k<=n;k++){
        if(d[i][k]!=LONG_LONG_MAX&&d[k][j]!=LONG_LONG_MAX)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    }
    for(i=1;i<=q;i++){
        cin>>x>>y;
        ans=LONG_LONG_MAX;
        for(j=0;j<v[x].size();j++){
            for(k=0;k<v[y].size();k++){
                ans=min(ans,d[v[x][j].u][v[y][k].u]+v[x][j].v+v[y][k].v);
            }
        }
        cout<<ans+a[x]+a[y]<<"\n";
    }
    return 0;
}
