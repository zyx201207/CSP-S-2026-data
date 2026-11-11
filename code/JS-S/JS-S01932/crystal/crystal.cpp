#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
LL n,m,a[N],s[N],ans;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid;
        mid=(l+r)>>1;
        while(l<r){
            mid=(l+r)>>1;
            if(a[i]*(LL)(i-mid+1)-(s[i]-s[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,(LL)(i-l+1));
    }
    cout<<ans<<endl;
    return 0;
}
