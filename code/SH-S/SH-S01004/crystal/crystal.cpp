#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long Maxn=500005;
ll n,m,ans;
ll a[Maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    if(n<=5000){
        for(ll i=1;i<=n;i++){
            ll standard=a[i],cnt=0,m1=m;
            for(ll j=1;j<=n&&a[j]<=standard;j++){
                if(a[j]==standard){
                    cnt++;
                }else{
                    ll tmp=standard-a[j];
                    if(tmp<=m1){
                        m1-=tmp;
                        cnt++;
                    }
                }
            }
            ans=max(ans,cnt);
        }
    }else{
        ll add=a[2]-a[1];
        for(ll i=n;i>=1;i--){
            ll tmp=add*(n-i);
            if(m>=tmp){
                m-=tmp;
                ans++;
            }
        }
    }
    printf("%lld\n",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
