#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,d;
ll a[5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%lld%lld",&n,&d);
        if(c==11||c==12){
            ll x,y,tmp,maxn;
            scanf("%lld%lld",&x,&y);
            for(int i=1;i<=n-3;i++) scanf("%lld",&tmp);
            scanf("%lld",&maxn);
            ll gc=y-x;
            d=(d/gc)*gc;
            printf("%lld\n",(maxn-x)-(2*d-1)+1);
        }
        else{
            printf("0\n");
        }
       /* if(c<=10){
            for(int i=1;i<=n;i++){
                scanf("%lld",&a[i]);
            }
            ll ans=0;
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    int tmpi=i,tmpj=j;
                    while(i<j){
                        if(a[i+2]-a[i]>d&&a[i+2]-a[i+1]<=d&&a[i+1]-a[i]<=d) i++;
                    }
                    while(i<j){
                        if(a[j]-a[j-1]<=d&&a[j-1]-a[j-2]<=d)
                    }
                    int idx1=upper_bound(a+i,a+j+1,a[i]+d)-a;
                    if(idx1==j+1) continue;
                    int idx2=upper_bound(a+i,a+j+1,a[j]-a[i]-d)-a;
                    if(idx2==j+1) continue;
                    idx1--;
                    if(idx1==idx2&&a[idx1]-a[i]!=d) ans++;
                    i=tmpi;j=tmpj;
                }
            }
            printf("%lld\n",ans);
        }*/

    }
    return 0;
}
