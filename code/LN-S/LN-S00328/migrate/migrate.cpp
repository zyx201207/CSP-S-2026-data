#include<bits/stdc++.h>
using std::sort;
int c , t , n ;
long long d , x[5050] ;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        sort(x+1,x+n+1);
        if(d<x[2]-x[1]){printf("0\n");continue;}
        long long ans=0LL;
        int delta=d/(x[2]-x[1]);
        for(int i=delta+1;i<n;i++){
            if(i%delta!=0) ans+=(n-i);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
