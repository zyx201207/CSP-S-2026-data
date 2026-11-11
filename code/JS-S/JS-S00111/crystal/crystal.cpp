#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l=1,r,ans,a[550000],pre[550000];
bool check(int x){
    int cst=2e18;
    for(int i=x;i<=n;++i){
        cst=min(cst,a[i]*x-pre[i]+pre[i-x]);
    }
    return cst<=m;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    r=n;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        a[i]+=1e12;
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        pre[i]=pre[i-1]+a[i];
    }
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}
