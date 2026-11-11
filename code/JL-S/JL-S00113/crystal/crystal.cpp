#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int n,m,a[N],b[N],ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i-1;
        while(l<r){
            int mid=l+r>>1;
            if(b[i]-b[mid-1]>=a[i]*(i-mid+1)-m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
}
