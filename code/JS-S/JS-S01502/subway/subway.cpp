#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
long long dis[505][505];
struct node{
    int x,t;
};
vector<node>a[505];
unordered_map<int,int>mp[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof dis);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++)
        scanf("%d",w+i);
    for(int i=1,x,t;i<=n;i++){
        scanf("%d",k+i);
        for(int j=1;j<=k[i];j++){
            scanf("%d%d",&x,&t);
            a[i].push_back({x,t});
            mp[x][i]=t;
        }
    }
    for(int i=1;i<=n;i++)
        dis[i][i]=0;
    for(int i=1;i<=n;i++){
        for(auto pos:a[i]){
            for(auto it:mp[pos.x]){
                if(pos.t+it.second<dis[i][it.first])
                    dis[i][it.first]=pos.t+it.second;
            }
        }
    }
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            for(int k=1;k<=n;k++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    for(int sss=1;sss<=q;sss++){
        int u,v;
        long long ans=0x3f3f3f3f3f3f3f3f;
        scanf("%d%d",&u,&v);
        for(auto i:mp[u])
            for(auto j:mp[v])
                ans=min(ans,dis[i.first][j.first]+i.second+j.second+w[u]+w[v]);
        printf("%lld\n",ans);
    }
    return 0;
}
//1h33min AC
