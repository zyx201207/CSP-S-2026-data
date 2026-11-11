#include<bits/stdc++.h>
using namespace std;\
long long n,m,k[500005],cnt;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&k[i]);

    }
    for(long long i=1;i<=m;i++){
        cnt+=i;
        if(cnt>m){
            printf("%lld",i);
            break;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
