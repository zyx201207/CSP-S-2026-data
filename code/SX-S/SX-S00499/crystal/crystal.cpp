#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500005],b[500005],ans=1;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) a[i]=a[i+1]-a[i];
    for(int i=2;i<=n;i++){
        for(int j=1;j<=n-i+1;j++){
            if(b[j]<m) b[j]=b[j]+(i-1)*a[i-1];
            else b[j]=LLONG_MAX;
            if(b[j]<=m) ans=max(ans,i);
        }
    }
    cout<<ans;
    return 0;
}
unsigned long long rp=-1;