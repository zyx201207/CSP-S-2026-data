#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
int lst[N];
int n,ans;
ll a[N],sum[N];
ll m;
bool check(int l,int r){
    return 1ll*(r-l+1)*a[r]-(sum[r]-sum[l-1])<=m;
}
void Files(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
}
int main(){
    Files();
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        if(i==1||a[i]!=a[i-1]) lst[i]=i;
        else lst[i]=lst[i-1];
    }
    for(int i=1;i<=n;i++){
        if(i!=n&&a[i]==a[i+1]) continue;
        int l=1,r=lst[i],mid;
        while(1){
            if(r-l<=1){
                if(check(l,lst[i])) ans=max(ans,i-l+1);
                else ans=max(ans,i-r+1);
                break;
            }
            mid=(l+r)>>1;
            if(check(mid,lst[i])) r=mid;
            else l=mid+1;
        }
    }
    printf("%d\n",ans);
    return 0;
}
