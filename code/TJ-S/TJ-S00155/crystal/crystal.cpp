#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll a[maxn],s[maxn];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    ll m;
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int res=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i,p=i;
        while(l<=r){
            int mid=(l+r)>>1;
            ll cost=1ll*(i-mid+1)*a[i]-(s[i]-s[mid-1]);
            if(cost<=m){
                p=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        res=max(res,i-p+1);
    }
    printf("%d\n",res);
    return 0;
}