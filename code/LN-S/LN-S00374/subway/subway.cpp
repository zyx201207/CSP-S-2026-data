#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,q,x,y,z;
int w[500010];
int d[510][510];
vector<pair<int,int>> a[500010];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&x,&m,&n,&x,&q);
    for(int i=1;i<=n;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%lld",&x);
        while(x--){
            scanf("%lld%lld",&y,&z);
            a[y].push_back({i,z});
        }
    }
    memset(d,0x3f,sizeof(d));
    for(int i=1;i<=m;i++){
        d[i][i]=0;
    }
    for(int p=1;p<=n;p++){
        for(auto i:a[p]){
            for(auto j:a[p]){
                d[i.first][j.first]=min(d[i.first][j.first],i.second+j.second);
            }
        }
    }
    for(int k=1;k<=m;k++){
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    int ans=0;
    while(q--){
        scanf("%lld%lld",&x,&y);
        ans=0x3f3f3f3f3f3f3f3f;
        for(auto i:a[x]){
            for(auto j:a[y]){
                ans=min(ans,i.second+d[i.first][j.first]+j.second);
            }
        }
        printf("%lld\n",ans+w[x]+w[y]);
    }
    return 0;
}
