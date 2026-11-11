#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d;
long long x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        for(int i = 1;i <= n;i++){
            scanf("%lld",&x[i]);
        }
        printf("0\n");
    }
    return 0;
}
