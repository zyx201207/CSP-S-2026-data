#include<bits/stdc++.h>
using namespace std;

long long c,n,m,d,q,mp[5120][5120],w[114514];

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    long long line[114514],linet[114514];
    for(int i=1;i<=m;i++){
        scanf("%lld",&w[i]);
    }
    memset(mp,1LL,sizeof(mp));
    for(int i=1;i<=n;i++){
        long long k;
        scanf("%lld",&k);
        for(int j=1;j<=k;j++){
            scanf("%lld%lld",&line[j],&linet[j]);
        }
        for(int stp=1;stp<=k;stp++){
            for(int edp=stp+1;edp<=k;edp++){
                mp[line[stp]][line[edp]]=linet[stp]+linet[edp];
                mp[line[edp]][line[stp]]=linet[stp]+linet[edp];
                //printf("Newpath %lld-%lld:%lld(%lld,%lld)\n",line[stp],line[edp],mp[line[stp]][line[edp]],linet[stp],linet[edp]);
            }
        }
    }
    //for(int i=1;i<=m;i++){
    //    for(int j=1;j<=m;j++){
    //        printf("%lld[%lld] ",mp[i][j],mp[i][j]+w[i]+w[j]);
    //    }
    //    printf("\n");
    //}
    //printf("---\n");
    bool flag=1;
    while(flag){
        flag=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=m;j++){
                for(int k=i;k<=m;k++){
                    if(mp[i][k]>mp[i][j]+mp[j][k]){
                        flag=1;
                        mp[i][k]=mp[i][j]+mp[j][k];
                        mp[k][i]=mp[i][j]+mp[j][k];
                    }
                }
            }
        }
    }
    //for(int i=1;i<=m;i++){
    //    for(int j=1;j<=m;j++){
    //        printf("%lld[%lld] ",mp[i][j],mp[i][j]+w[i]+w[j]);
    //    }
    //    printf("\n");
    //}
    while(q--){
        long long st,ed;
        scanf("%lld%lld",&st,&ed);
        printf("%lld\n",mp[st][ed]+w[st]+w[ed]);
    }
    return 0;
}
