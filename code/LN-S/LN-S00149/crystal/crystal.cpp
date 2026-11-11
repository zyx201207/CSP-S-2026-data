#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int maxn=5e5+5;
int a[maxn],n,m,sum[maxn],ans;
int ck(int mid,int i){
    int ned=a[i]*(i-mid+1)-(sum[i]-sum[mid-1]);
    return ned;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%lld%lld",&n,&m);
    
    //cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        // cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    ans=1;
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        while(l<r){
            mid=(l+r)>>1;//please check is l+r+1 or l+r   significant!!
            if(ck(mid,i)<=m) r=mid;//r=mid than r is answer 
            else l=mid+1;
        }
        ans=max(ans,i-r+1);
    }
    printf("%lld\n",ans);


    return 0;
}