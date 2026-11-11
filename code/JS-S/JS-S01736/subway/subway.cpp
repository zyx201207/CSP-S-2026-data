#include<bits/stdc++.h>
using namespace std;
typedef long long lll;
const int N=5e5;
lll c,n,d,m,q,w[N+5];
void sol1(){
    lll a[602][602],k,u,v,c;
    for(int i=1;i<=600;++i){
        for(int j=1;j<=600;++j){
            if(i!=j){
                a[i][j]=LONG_LONG_MAX/2-1;
            }
        }
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&k);
        for(int j=1;j<=k;++j){
            scanf("%lld%lld",&v,&c);
            a[m+i][v]=a[v][m+i]=c;
        }
    }
    for(int k=1;k<=n+m;++k){
        for(int i=1;i<=n+m;++i){
            for(int j=1;j<=n+m;++j){
                a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
            }
        }
    }
    for(int i=1;i<=q;++i){
        scanf("%lld%lld",&u,&v);
        printf("%lld\n",a[u][v]+w[u]+w[v]);
    }
}
void sol2(){
    lll a[602][602],k,u,v,c1,c2;
    for(int i=1;i<=600;++i){
        for(int j=1;j<=600;++j){
            if(i!=j){
                a[i][j]=LONG_LONG_MAX/2-1;
            }
        }
    }
    for(int i=1;i<=n;++i){
        scanf("%lld",&k);
        if(k==2){
            scanf("%lld%lld%lld%lld",&u,&c1,&v,&c2);
            a[u][v]=a[v][u]=c1+c2;
        }
    }
    for(int k=1;k<=m;++k){
        for(int i=1;i<=m;++i){
            for(int j=1;j<=m;++j){
                a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
            }
        }
    }
    for(int i=1;i<=q;++i){
        scanf("%lld%lld",&u,&v);
        printf("%lld\n",a[u][v]+w[u]+w[v]);
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
     for(int i=1;i<=m;++i){
        scanf("%lld",w+i);
    }
    if(c<=7){
        sol1();
    }
    else if(9<=c&&c<=11){
        sol2();
    }
    return 0;
}
