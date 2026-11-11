#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m,a[N],b[N];
bool check(int x){
    int mincost=9e18;
    for(int i=1;i<=n-x+1;++i){
        mincost=min(mincost,(x-1)*a[i+x-1]+b[i-1]-b[i+x-2]);
    }
    return mincost<=m;
}
int solve(int l,int r){
    if(l==r) return l;
    int mid=(l+r+1)/2;
    if(check(mid)) return solve(mid,r);
    else return solve(l,mid-1);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        b[i]=b[i-1]+a[i];
    }
    cout<<solve(1,n);
    return 0;
}
