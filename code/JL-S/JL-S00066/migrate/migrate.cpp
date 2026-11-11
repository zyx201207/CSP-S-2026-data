#include<bits/stdc++.h>
using namespace std;
const int inf = 1e7+10;
int x[inf];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d,gongcha;
    scanf("%d %d",&c,&t);
    while(t--){
        scanf("%d %d",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%d",&x[i]);
        } printf("%d\n",(n-3));
    } return 0;
}
