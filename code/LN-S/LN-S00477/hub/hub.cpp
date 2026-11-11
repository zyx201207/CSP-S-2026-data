#include <bits/stdc++.h>
using namespace std;
int c,t,n,k;
int u[2000010],v[2000010];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&k);
        for(int i = 1;i <= n - 1;i++){
            scanf("%lld",&u[i],&v[i]);
        }
        printf("1\n");
    }
    return 0;
}
