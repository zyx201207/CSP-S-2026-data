#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans,minn,a[1<<20],s[1<<20];
int mid_find(int l,int r,int num,int last){
    if(l>=r){
        if(a[num]-a[l]>last){
            return l+1;
        }else{
            return l;
        }
    }
    int mid=(l+r)/2;
    if((r-mid)*a[num]-s[r]+s[mid]<=last){
        return mid_find(l,mid,num,last-((r-mid)*a[num]-s[r]+s[mid]));
    }else{
        return mid_find(mid+1,r,num,last);
    }
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(ans,i-mid_find(1,i,i,m)+1);
    }
    cout<<ans;
    return 0;
}