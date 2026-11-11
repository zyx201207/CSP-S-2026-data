#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,s[N],a[N],ans=1;
bool check(int x){
    bool f=0;
    for(int i=1;i+x-1<=n;i++){
        int nd=(x-1)*a[i+x-1]-(s[i+x-2]-s[i-1]);
        if(nd<=m){
            f=1;
            break;
        }
    }
    return f;
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
    int l=2,r=n;
    while(l<=r){
        int mid=(l+r)>>1;
        if(check(mid))ans=mid,l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}