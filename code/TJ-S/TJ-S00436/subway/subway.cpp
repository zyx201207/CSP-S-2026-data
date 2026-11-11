#include<bits/stdc++.h>
using namespace std;

long long w[22222]={0};
long long k[2222]={0};
long long a[2222][22222]={0},t[2222][22222]={0};
long long s[22222][555]={0};

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    int c=0;
    long long n=0,m=0,d=0,q=0;
    scanf("%d%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(long long i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    for(long long i=1;i<=n;i++){
        scanf("%lld",&k[i]);
        for(long long j=1;j<=k[i];j++){
            scanf("%lld%lld",&a[i][j],&t[i][j]);
            s[a[i][j]][i]++;
        }
    }

    while(q--){
        long long x=0,y=0;
        scanf("%lld%lld",&x,&y);

        long long ans=0;
        ans+=w[x];

    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
