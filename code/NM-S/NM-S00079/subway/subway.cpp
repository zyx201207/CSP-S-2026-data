#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c=0,n=0,m=0,d=0,q=0;
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    long long w[200000]={};
    for(long long i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    long long k[1000]={};
    long long a[505][505]={},t[505][505]={};
    for(int i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
        }
    }
    long long x[100005]={},y[100005]={};
    for(int i=1;i<=q;i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    return 0;
}
