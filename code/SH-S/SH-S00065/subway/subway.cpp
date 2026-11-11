#include <bits/stdc++.h>
using namespace std;
int w[500010];
long long g2[510][510],dis2[510][510];
vector<pair<int,int>> g1[500010];
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    memset(g2,0x3f,sizeof(g2));
    for(int i=1;i<=m;++i)cin>>w[i];
    for(int i=1,k;i<=n;++i){
        cin>>k;
        for(int j=1,a,t;j<=k;++j){
            cin>>a>>t;
            g1[a].push_back({i,t});
        }
    }
    for(int i=1;i<=m;++i)
        for(int j=0;j<g1[i].size();++j)
            for(int k=j+1;k<g1[i].size();++k){
                auto u=g1[i][j];
                auto v=g1[i][k];
                //cout<<u.first<<' '<<v.first<<"IWILLAK\n";
                g2[u.first][v.first]=g2[v.first][u.first]=min(g2[u.first][v.first],(long long)(u.second+v.second));
            }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j)
    //         cout<<g2[i][j]<<' ';
    //     cout<<'\n';
    // }
    memset(dis2,0x3f,sizeof(dis2));
    for(int i=1;i<=n;++i){
        dis2[i][i]=0;
        for(int j=i+1;j<=n;++j)
            dis2[i][j]=dis2[j][i]=g2[i][j];
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                dis2[i][j]=min(dis2[i][j],dis2[i][k]+dis2[k][j]);
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=n;++j)
    //         cout<<dis2[i][j]<<' ';
    //     cout<<'\n';
    // }
    int qs,qt;
    long long ans;
    while(q--){
        cin>>qs>>qt;
        if(qs==qt){
            cout<<"0\n";
            continue;
        }
        ans=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<g1[qs].size();++i)
            for(int j=0;j<g1[qt].size();++j){
                auto u=g1[qs][i];
                auto v=g1[qt][j];
                ans=min(ans,dis2[u.first][v.first]+u.second+v.second);
            }
        cout<<ans+w[qs]+w[qt]<<'\n';
    }
    return 0;
}