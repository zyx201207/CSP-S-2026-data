#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500001],b[500001],u;
ll ans,cnt,t;
int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    if(n<=5000){
        for(int i=1;i<=n;i++){
            u=0;
            for(int j=i;j>=1;j--){
                u+=a[i]-a[j];
                if(u>m){
                    break;
                }
                cnt=j;
            }
            ans=max(ans,i-cnt+1);
        }
    }else{
        u=1;
        t=1;
        ans=1;
        for(int i=2;i<=n;i++){
            cnt+=(a[i]-a[i-1])*u;
            while(cnt>m){
                cnt-=a[i]-a[t];
                t++;
                u--;
            }
            u++;
            ans=max(ans,u);
            //cout<<"de:"<<i<<" "<<u<<" "<<ans<<endl;
        }
    }
    printf("%lld",ans);
    return 0;
}
