#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+7;
ll n,m,a[N],s[N];

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            ll cnt=i-mid+1;
            if(a[i]*cnt-(s[i]-s[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        //cerr<<i<<' '<<l<<endl;//
        ans=max(ans,i-l+1);
    }
    printf("%d",ans);
    return 0;
}