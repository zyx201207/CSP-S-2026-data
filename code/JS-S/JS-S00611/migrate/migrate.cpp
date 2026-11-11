#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
int c,T,n,d,x[N];

void solve1(){
    int t = d / (x[2] - x[1]);
    if(t == 0 || t == 1){
        printf("0\n");
        return;
    }
    int ans = ((n - 1) / t) * t * (t - 1) + ((n - 1) % t) * ((n - 1) % t) / 2;
    printf("%d\n",ans);
}

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        scanf("%d%d",&n,&d);
        for(int i = 1;i <= n;i++){
            scanf("%d",&x[i]);
        }
//        if(c == 11 || c == 12) solve1();
        solve1();
    }


    return 0;
}
/*
qwertyuiopasdfghjklzxcvbnm

*/
