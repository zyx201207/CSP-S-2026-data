#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
long long c,n,m,d,q,floyd[5005][5005],w[500005],a[500005],t[500005],need[500005],need2[500005],cnt[500005];
bool f[500005],f2[500005];
struct node{
    int v,w;
    node(int a,int b):v(a),w(b){}
};
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    if(c==20 || c==21){
        if(n==1){
            for(int i=1;i<=m;i++)cin>>w[i];
            for(int i=1;i<=n;i++){
                int k;
                cin>>k;
                for(int j=1;j<=k;j++){
                    cin>>a[j]>>t[j];
                    need[a[j]]=t[j];
                }
            }
            while(q--){
                int u,v;
                cin>>u>>v;
                cout<<w[u]+w[v]+need[u]+need[v]<<"\n";
            }
        }
        else{
            for(int i=1;i<=m;i++)cin>>w[i];
            long long k,minn=10000000000LL;
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>a[j]>>t[j];
                need[a[j]]=t[j];
                f[a[j]]=1;
            }
            cin>>k;
            for(int j=1;j<=k;j++){
                cin>>a[j]>>t[j];
                need2[a[j]]=t[j];
                f2[a[j]]=1;
                if(f[a[j]])minn=min(minn,need[a[j]]+need2[a[j]]);
            }
            while(q--){
                int u,v;
                cin>>u>>v;
                long long ans=10000000000LL;
                if(f[u] && f[v])ans=min(ans,need[u]+need[v]);
                if(f2[u] && f2[v])ans=min(ans,need2[u]+need2[v]);
                if(f[u] && f2[v])ans=min(ans,need[u]+need2[v]+minn);
                if(f2[u] && f[v])ans=min(ans,need2[u]+need[v]+minn);
                cout<<ans+w[u]+w[v]<<"\n";
            }
        }
    }
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=m;i++)for(int j=1;j<=m;j++)floyd[i][j]=0x3f3f3f3f*(i!=j);
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)cin>>a[j]>>t[j];
        for(int j=1;j<=k;j++){
            for(int l=1;l<=k;l++){
                floyd[a[j]][a[l]]=min(floyd[a[j]][a[l]],t[j]+t[l]);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                floyd[i][j]=min(floyd[i][j],floyd[i][k]+floyd[k][j]);
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        cout<<w[u]+w[v]+floyd[u][v]<<"\n";
    }
    return 0;
}
