#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],s[N];
bool check(int x){
    int k=a[x];
    return k*(x-1)-s[x-1]<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","W",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
