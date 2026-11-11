#include<bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,l,r) for(int i=(l);i<=(r);i++)
#define per(i,r,l) for(int i=(r);i>=(l);i--)
#define N 501114
int n,m,a[N],ans,pre[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;rep(i,1,n)cin>>a[i];sort(a+1,a+n+1);rep(i,1,n)pre[i]=pre[i-1]+a[i];
    rep(i,1,n){
        int l=1,r=i,p=i;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])<=m)p=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-p+1);
    }
    cout<<ans;
}