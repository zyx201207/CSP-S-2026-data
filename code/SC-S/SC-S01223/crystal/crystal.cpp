#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,ans;
long long m,a[N],s[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    ans=1;
    for(int i=n;i>=1;i--){
        int l=0,r=i,tmp=0;
        while(l<=r){
            int mid=(l+r)>>1;
            // cout<<i<<" "<<l<<" "<<r<<" "<<mid<<" "<<(i-1-mid)*a[i]<<" "<<(s[i-1]-s[mid])<<endl;
            if((i-1-mid)*1ll*a[i]-(s[i-1]-s[mid])<=m) tmp=(i-mid),r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,tmp);
    }
    printf("%d\n",ans);
    return 0;
}