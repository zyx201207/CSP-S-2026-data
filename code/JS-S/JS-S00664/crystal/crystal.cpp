#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+5;
int n,m;
int a[MAXN],sum[MAXN];
bool check(int l,int r){return a[r]*(r-l+1)-sum[r]+sum[l-1]<=m;}
int solve(int x){
    int l=x,r=n,ret=0;
    while(l<=r){
        int mid=((r-l)>>1)+l;
        if(check(x,mid)){
            ret=mid-x+1;
            l=mid+1;
        }
        else r=mid-1;
    }
    return ret;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=n;i++) ans=max(ans,solve(i));
    cout<<ans;
    return 0;
}
