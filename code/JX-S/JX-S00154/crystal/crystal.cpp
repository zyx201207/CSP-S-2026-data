#include <bits/stdc++.h>
using namespace std;
#define int long long
const int nn=5e5+5;
int n,m,a[nn],s[nn],ans;
int get_lr(int l,int r){
    return s[r]-s[l-1];
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    for(int i=1;i<=n;i++){
        int l=1,r=i,mid,sum=i;
        while(l<=r){
            mid=(l+r)/2;
            if(get_lr(mid,i)+m>=a[i]*(i-mid+1))sum=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,(i-sum+1));
    }
    cout<<ans;
    return 0;
}
