#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,T;
ll n,d;
ll x[2000010];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&T);
    while(T--){
        ll ans=0;
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                ll dis=x[j]-x[i];
                int kkk=dis%d;
                if(dis>d&&kkk!=0){
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
