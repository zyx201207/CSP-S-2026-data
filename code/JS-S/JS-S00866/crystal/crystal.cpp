#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7;
int n,m,l,r,mid,ans=1,a[maxn],pre[maxn];
signed main()
{
    /*
    If you see it,you will see this:
    When you are seeing this,you have seen these.
    */
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    pre[1]=0;
    for(int i=2,j=1;i<=n;i++,j++){
        pre[i]=pre[i-1]+(a[i]-a[i-1])*j;
        if(pre[i]<=m){
            ans=max(ans,i);
        }
        else{
            l=1,r=i-1,mid=(l+r)>>1;
            while(l<r){
                if(pre[i]-(pre[mid]+(a[i]-a[mid])*(mid-1))<=m){
                    r=mid;
                }
                else{
                    l=mid+1;
                }
                mid=(l+r)>>1;
            }
            ans=max(ans,i-mid+1);
        }
    }
    printf("%lld",ans);
    return 0;
}
