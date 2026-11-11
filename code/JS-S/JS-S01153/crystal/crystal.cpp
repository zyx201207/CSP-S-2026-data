#include<cstdio>
#include<algorithm>
using namespace std;
const int s=1000000;
using ll=long long;
ll n,m,tot=0;
ll a[s],b[s];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        if(a[i]==a[i-1])b[tot]++;
        else b[++tot]++;
    }
    unique(a+1,a+n+1);
    ll ans=-1;
    for(ll i=1;i<=tot;i++){
        ll now=b[i];
        ll _m=m,j=1;
        while(_m>0&&i-j>=1){
            ll del=a[i]-a[i-j];
            ll ned=b[i-j]*del;
            if(ned<=_m){
                _m-=ned;
                now+=b[i-j];
            }
            else{
                now+=_m/del;
                _m=0;
            }
            j++;
        }
        ans=max(ans,now);
    }
    printf("%lld",ans);
}
