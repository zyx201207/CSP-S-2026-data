#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,a[N],m,pre[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        long long l=1,r=i;
        while(l<r){
            long long mid=(l+r)>>1;
            if(a[i]*(i-mid+1ll)-pre[i]+pre[mid-1]>m) l=mid+1;
            else r=mid;
        }
        ans=max(ans,i-l+1ll);
    }
    cout<<ans;
    return 0;
}
