#include<bits/stdc++.h>
using namespace std;
long long w[500005],n,m,c,q,d,k[505],dis[505][505];
struct aori{
    long long v,t;
};
vector <aori> v[500005],v2[505];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    for(int i=1;i<=500;i++){
        for(int j=1;j<=500;j++){
            if(i!=j) dis[i][j]=99999999999999;
        }
    }

    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            long long a,t;
            scanf("%lld%lld",&a,&t);
            v[a].push_back({i,t});
            v2[i].push_back({a,t});
        }
    }

    for(int i=1;i<=n;i++){
        for(aori j:v2[i]){
            long long x=j.v;
            for(aori l:v[x]){
                dis[i][l.v]=min(dis[i][l.v],j.t+l.t);
            }
        }
    }

    for(int l=1;l<=n;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dis[i][j]=min(dis[i][l]+dis[l][j],dis[i][j]);
            }
        }
    }

    while(q--){
        long long l,r;
        scanf("%lld%lld",&l,&r);
        long long ans=99999999999999;
        for(aori i:v[l]){
            for(aori j:v[r]){
                ans=min(ans,i.t+j.t+dis[i.v][j.v]);
            }
        }
        printf("%lld\n",(ans+w[l]+w[r]));
    }
    return 0;
}
