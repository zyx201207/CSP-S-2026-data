#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    ll ans=0;
    for(int i=1;i<=n;i++){
        a[i]+=a[i-1];
    }
    for(int i=1,j=0;i<=n;i++){
        while((i-j)*(a[i]-a[i-1])-(a[i]-a[j])>m){
            j++;
        }
        if(ans<i-j)ans=i-j;
    }
    printf("%lld\n",ans);
    return 0;
}
