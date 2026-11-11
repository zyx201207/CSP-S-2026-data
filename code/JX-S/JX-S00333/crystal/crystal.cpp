#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int M = 5e5 + 10;
ll a[M],b[M];
ll n,m;
bool check(int l,int r){
    ll sum = a[r]*(r-l+1)-(b[r]-b[l-1]);
    return sum<=m;
}
int sovle(int x){
    /*
    for(int i=1;i<=x;i++) if(check(i,x))return x-i+1;
    */
    int l = 1,r = x;
    while(l<r){
        int mid = (l+r)>>1;
        if(check(mid,x)) r = mid;
        else l = mid + 1;
    }
    return x-r+1;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) b[i] = b[i-1] + a[i];
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(a[i]==a[i+1])continue;
        ans = max(ans,sovle(i));
    }
    printf("%d",ans);
    return 0;
}
