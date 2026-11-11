#include<iostream>
#include<vector>
using namespace std;
using ll=long long;
const int MAXN=505;
const int MAXM=5e5+5;
int c,n,m,d,q;
ll w[MAXM];
vector<pair<int,ll> > a[MAXM];
ll G[MAXN][MAXN];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    int k;
    for(int i=1;i<=n;i++){
        int a1;
        ll t1;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            scanf("%d %lld",&a1,&t1);
            a[a1].push_back({i,t1});
        }
    }
    // for(int i=1;i<=n;i++){
    //     G[i][i]=0;
    //     for(int j=1;j<i;j++){
    //         G[i][j]=1e18;
    //         for(auto k:a[i]){
    //             if(a[j].count(k.first)!=0){
    //                 G[i][j]=min(G[i][j],k.second+a[j][k.first]);
    //             }
    //         }
    //         G[j][i]=G[i][j];
    //         cerr<<"###G:"<<i<<" "<<j<<" "<<G[i][j]<<"\n";
    //     }
    // }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                G[i][j]=0;
            }else{
                G[i][j]=1e18;
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<a[i].size();j++){
            for(int k=0;k<j;k++){
                G[a[i][j].first][a[i][k].first]=min(G[a[i][j].first][a[i][k].first],a[i][j].second+a[i][k].second);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            ll tmp=min(G[i][j],G[j][i]);
            G[i][j]=tmp;
            G[j][i]=tmp;
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
            }
        }
    }
    int u,v;
    while(q--){
        ll ans=1e18;
        scanf("%d %d",&u,&v);
        for(auto i:a[u]){
            for(auto j:a[v]){
                ans=min(ans,i.second+j.second+G[i.first][j.first]);
            }
        }
        printf("%lld\n",ans+w[u]+w[v]);
    }
    return 0;
}