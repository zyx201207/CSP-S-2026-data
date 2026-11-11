#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005],sum[500005];
int n,m;
bool check(int mid){
    for (int i=1;i+mid-1<=n;i++){
        int s=sum[i+mid-1]-sum[i-1];
        s+=m;
        if (s>=a[i+mid-1]*mid)return true;
    }
    return false;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int l=1,r=n,ans=1;
    while (l<=r){
        int mid=(l+r)/2;
        if (check(mid)==true){
            l=mid+1;
            ans=mid;
        }
        else{
            r=mid-1;
        }
    }
    printf("%lld\n",ans);
    return 0;
}