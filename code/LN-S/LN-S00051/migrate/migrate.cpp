#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=2e6+5;
int c,t,n,d;
ll x[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&d);
        for(int i=1;i<=n;++i){
            scanf("%lld",&x[i]);
        }
        int tmp=d/(x[2]-x[1]);
        if(tmp<=1||n-(tmp+2)-1<0)printf("0\n");
        else printf("%d\n",n-(tmp+2)-1);
    }
    return 0;
}
