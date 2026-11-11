#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p,u,v,k,w[500005],G[505][505];
vector<int>t[500005],h[500005];
priority_queue<pair<long long,int> > q;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>p;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=n;j++) G[i][j]=1e18;
        G[i][i]=0;
        for(int j=1;j<=k;j++){
            cin>>u>>v;
            h[u].push_back(i);
            t[u].push_back(v);
        }
    }
    for(int i=1;i<=m;i++){
        int l=h[i].size();
        for(int j=0;j<l;j++){
            for(int k=0;k<l;k++){
                G[h[i][j]][h[i][k]]=min(t[i][j]+t[i][k]+0ll,G[h[i][j]][h[i][k]]);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                G[j][k]=min(G[j][k],G[j][i]+G[i][k]);
            }
        }
    }
    for(int i=1;i<=p;i++){
        cin>>u>>v;
        int lu=h[u].size(),lv=h[v].size();
        long long ans=1e18;
        for(int i=0;i<lu;i++){
            for(int j=0;j<lv;j++){
                ans=min(G[h[u][i]][h[v][j]]+t[u][i]+t[v][j],ans);
            }
        }
        cout<<ans+w[u]+w[v]<<'\n';
    }
    return 0;
}