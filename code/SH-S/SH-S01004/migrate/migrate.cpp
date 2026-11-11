#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d,t,c,ans;
ll pos[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&pos[i]);
        }
        for(int len=4;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                if(pos[j]-pos[i]>d&&pos[j]-pos[i]<2*d){
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
        ans=0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
