#include<iostream>
#include<algorithm>

#define int long long

using namespace std;

int n,m;
int a[500005];
int f[500005];

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i)
        f[i]=f[i-1]+a[i];
    int ans=0;
    for(int i=1;i<=n;++i){
        int l=1,r=i,ret=i+1;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(f[i]-f[mid-1])<=m){
                ret=mid;
                r=mid-1;
            }else
                l=mid+1;
        }
        ans=max(ans,i-ret+1);
    }
    cout<<ans<<endl;
    return 0;
}