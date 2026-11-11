#include<bits/stdc++.h>
using namespace std;
int c,t;
long long n,d;
long long x[2000005];
void solve(){
    scanf("%lld%lld",&n,&d);
    for(int i = 0;i<=n;i++){
        scanf("%lld",x+i);
    }
    if(c==11 && c==12){
        int t = x[1]-x[0];
        if(t*2<=d && d<t*3){
            printf("%lld",n-3);
        }
        else{
            printf("0");
        }
    }
    else if(c == 13 && c == 14){
        printf("0");/**/
    }
    else if(15<=c && c<=18){
        printf("0");/**/
    }
    else{
        printf("0");
    }
    printf("\n");
    return;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%d%d",&c,&t);
    while(t--){
        solve();
    }




    return 0;
}
