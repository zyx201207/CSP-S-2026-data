#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],qzh[N];
ll n,m;
bool check(int ck){
    for(int i=1;i<=(n-ck+1);i++){
        ll nowans=(qzh[i+ck-1]-qzh[i]-1ll*(a[i+ck-1]-a[i])*(i-1));
        if(nowans<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++)qzh[i]=1ll*(a[i]-a[i-1])*(i-1)+qzh[i-1];
    ll l=1ll,r=n;
    while(l<r){
        ll mid=(l+r+1ll)>>1;
        if(check(mid))l=mid;
        else r=mid-1ll;
    }
    printf("%lld\n",l);
    return 0;
}