#include<bits/stdc++.h>
using namespace std;
long long a[500003],pre[500003];
long long n,m;
bool check(int x){
    for(int i=x;i<=n;++i){
        int tmp=a[i]*x-(pre[i]-pre[i-x]);
        if(tmp<=m) return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;++i) pre[i]=pre[i-1]+a[i];
    int l=1,r=n,mid,ans;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
    return 0;
}
