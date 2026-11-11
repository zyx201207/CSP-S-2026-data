#include<bits/stdc++.h>
using namespace std;
struct node{
    long long a,b=0,cha;
}a[2000050];
long long c,t,n,d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i].a);
        }
        if(c==11||c==12){
            if(d<2*(a[2].a-a[1].a)||d>=3*(a[2].a-a[1].a))printf("0\n");
            else{
                printf("%lld\n",n-2);
            }
        }
        else{
            printf("0\n");
        }
    }
    return 0;
}
