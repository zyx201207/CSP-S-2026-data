#include<bits/stdc++.h>
using std::sort;
using std::max;
int n ;
long long m , a[500500] , s[500500] ;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    s[0]=0;
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=0 , r=i;
        while(l+1<r){
            int mid=(l+r)/2;
            if(1LL*(i-mid+1)*a[i]-(s[i]-s[mid-1]+1LL)<=m){
                r=mid;
            }
            else l=mid;
        }
        ans=max(ans,(i-r+1));
    }
    printf("%d\n",ans);
    return 0;
}
