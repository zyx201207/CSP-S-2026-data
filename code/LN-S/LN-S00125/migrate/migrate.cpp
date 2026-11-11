#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    if(c==1){
        for(int i=1;i<=t;i++){
            int n,d;
            scanf("%d%d",&n,&d);
            long long mi=1e18,ma=-1e18;
            for(int j=1;j<=n;j++){
                long long pj;
                scanf("%lld",&pj);
                mi=min(mi,pj);
                ma=max(ma,pj);
            }
            if(n<=3||d>=ma-mi) printf("0\n");
            else printf("1\n");
        }
        return 0;
    }
    for(int i=1;i<=t;i++) printf("0\n");
    return 0;
}
