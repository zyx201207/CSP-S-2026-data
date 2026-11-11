#include "bits/stdc++.h"
using namespace std;
long long n,m,a[500010],ans=0,bef=-1E12-1,ra;
bool tfc[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        tfc[i]=true;
    }
    sort(a+1,a+n+1);
    bef=a[1];
    for(int i=2;i<=n;i++){
        if(bef==a[i]){
            ra++;
            ans=max(ans,ra);
            continue;
        }
        int k=i;
        ra=0;
        long long usec=m;
        while(k>0&&usec>0){
            if(a[k]<=a[i]&&tfc[k]==true){
                usec-=(a[i]-a[k]);
                ra++;
            }
            if(usec<0||tfc[k]==false){
                ra--;
                tfc[k]=false;
                break;
            }
            k--;
        }
        ans=max(ans,ra);
    }
    printf("%lld",ans);
    return 0;
}
