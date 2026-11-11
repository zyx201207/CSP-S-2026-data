#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500005],a[500005],t[500005],e[1005][1005],dis[1005][1005],now,b,f;
struct node{
    long long x,y;
    bool operator<(const node p)const{
        return y>p.y;
    }
};
priority_queue<node> pq;
vector<long long> v[1005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
        e[i][i]=0;
    }
    for(int i=1;i<=n;i++){
        scanf("%lld",&b);
        for(int k=1;k<=b;k++){
            scanf("%lld%lld",&a[k],&t[k]);
            for(int j=1;j<k;j++){
                e[a[j]][a[k]]=e[a[k]][a[j]]=min(e[a[j]][a[k]],t[j]+t[k]);
            }
        }

    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=m;j++){
            if(e[i][j]!=0x3f3f3f3f3f3f3f3f)v[i].push_back(j);
        }
    }
    memset(dis,0x3f,sizeof(dis));
    for(int i=1;i<=m;i++){
        dis[i][i]=0;
        pq.push({i,0});
        while(!pq.empty()){
            now=pq.top().x;
            pq.pop();
            for(auto j:v[now]){
                if(dis[i][j]>dis[i][now]+e[now][j]){
                    dis[i][j]=dis[i][now]+e[now][j];
                    pq.push({j,dis[i][j]});
                }
            }
        }
    }
    while(q--){
        scanf("%lld%lld",&b,&f);
        printf("%lld\n",w[b]+w[f]+dis[b][f]);
    }
    return 0;
}
