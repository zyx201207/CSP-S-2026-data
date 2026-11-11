#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;

int a[N],pre[N],n,m,ans=0;

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) scanf("%lld",a+i);
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i-1,res=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m) res=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,(i-res+1));
    }
    cout<<ans<<endl;
    return 0;
}