#include"bits/stdc++.h"
using namespace std;
#define int long long
int n,m,a[500100],b[500100],sum,need,l=1,r=0,ans;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    for(int i=1;i<=n;i++){
        a[i]=b[i];
    }
    for(int i=1;i<=n;i++){
        r++;
        sum+=a[i];
        need+=(r-l)*a[i];
        while(need>m){
            need-=sum;
            sum-=a[++l];
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
}
