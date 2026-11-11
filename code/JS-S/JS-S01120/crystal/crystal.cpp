#include<bits/stdc++.h>
using namespace std;
long long l,r,mid,cnt,ans,ts;
long long m,n;
long long a[500005];
long long pre[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        //cin>>a[i];
    }

    sort(a+1,a+n+1);

    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        l=1,r=i-1;
        while(l<=r){
            mid=(l+r)/2;
            if(a[i]*(i-mid)-(pre[i-1]-pre[mid-1])<=m){
                cnt=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-cnt+1);
    }
    cout<<ans;
}
