#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m;
int a[N];
int ans;
int need[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        need[i]=need[i-1]+(i-1)*(a[i]-a[i-1]);
        int l=1,r=i;
        int res=1;
        while(l<=r){
            int mid=l+r>>1;
            if(need[i]-need[mid-1]-(mid-1)*(a[i]-a[mid-1])<=m){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        ans=max(ans,i-res+1);
    }
    cout<<ans<<endl;
    return 0;
}
