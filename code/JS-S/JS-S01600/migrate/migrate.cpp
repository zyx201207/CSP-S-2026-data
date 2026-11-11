#include<bits/stdc++.h>
using namespace std;
int c,t,n;

long long a[2000005],d;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%lld",&n,&d);
        long long ans=0;
        for(int i=1;i<=n;i++){
            scanf("%lld",&a[i]);
        }
        long long c=a[2]-a[1];
        if(2*c>d){
            printf("0\n");
        }
        else{
            long long y=d/c;
            long long l=2ll*y-1;
            printf("%lld\n",max(n-l,0ll));
        }
    }
}
