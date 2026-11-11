#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],pre[500005];
int get(int x){
    int l=1,r=x;
    while(l<r){
        int mid=(l+r)>>1;
        if((x-mid+1)*a[x]-(pre[x]-pre[mid-1])<=m)r=mid;
        else l=mid+1;
    }
    return x-l+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
    int ans=1;
    for(int i=1;i<=n;i++){
        ans=max(ans,get(i));
    }
    cout<<ans<<endl;
    return 0;
}