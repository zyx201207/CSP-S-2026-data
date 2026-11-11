#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ans,mn=1e12,mx=-1e12;
bool check(int x){
    int sum=0,cnt=0;
    for (int i=1;i<=n;i++)
        if (x>=a[i])cnt++,sum+=(x-a[i]);
    if (sum<=m){
        ans=max(ans,cnt);
        return 1;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i],mn=min(mn,a[i]),mx=max(mx,a[i]);
    sort(a+1,a+n+1);
    int l=mn,r=mx,mid;
    while(l<=r){
        mid=(l+r)/2;
        if (check(mid))l=mid+1;
        else r=mid-1;
    }
    cout<<ans;
    return 0;
}
