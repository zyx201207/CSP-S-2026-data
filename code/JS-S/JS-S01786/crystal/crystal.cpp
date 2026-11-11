#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m,ans=1;
    cin>>n>>m;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i) s[i]=s[i-1]+a[i];
    for(int i=n;i>=2;--i){
        int l=1,r=i-1,k=i;
        while(l<=r){
            int mid=l+r>>1;
            if(a[i]*(i-mid)-(s[i-1]-s[mid-1])<=m){
                k=mid;
                r=mid-1;
            }else l=mid+1;
        }
        ans=max(ans,i-k+1);
    }
    cout<<ans;
    return 0;
}
//18minAC
