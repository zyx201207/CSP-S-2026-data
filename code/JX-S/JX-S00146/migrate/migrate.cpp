#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long d,x[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d %d",&c,&t);
    for(int q=0;q<t;q++){
        scanf("%d %lld",&n,d);
        for(int i=0;i<n;i++) scanf("%lld",&x[i]);
        printf("%d",n/3);
    }
}
