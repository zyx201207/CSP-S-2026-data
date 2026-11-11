#include<bits/stdc++.h>
using namespace std;
int w[500005],a[505][500005],t[505][500005];
vector<int> s[500005];
long long dis[505][505];
int main(){
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++){
            int tt;
            scanf("%d%d",&a[i][j],&tt);
            t[i][a[i][j]]=tt;
            s[a[i][j]].push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j) dis[i][j]=0;
            else dis[i][j]=1e15;
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<s[i].size();j++){
            for(int k=j+1;k<s[i].size();k++){
                int u=s[i][j],v=s[i][k];
                dis[u][v]=t[u][i]+t[v][i];
                dis[v][u]=t[u][i]+t[v][i];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(dis[i][j]>dis[i][k]+dis[k][j]){
                    dis[i][j]=dis[i][k]+dis[k][j];
                    dis[j][i]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        long long ans=LLONG_MAX;
        for(int i:s[x]){
            for(int j:s[y]){
                if(dis[i][j]==LLONG_MAX) continue;
                ans=min(ans,dis[i][j]+t[i][x]+t[j][y]);
            }
        }
        ans+=(w[x]+w[y])*1ll;
        printf("%lld\n",ans);
    }
}
