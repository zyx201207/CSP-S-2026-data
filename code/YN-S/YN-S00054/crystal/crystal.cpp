#include<iostream>
#include<vector>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
    ios::sync_with_stdio();
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1),sum(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a.begin()+1,a.end());
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=1,r=i;
        while(l<r){
            int mid=l+r>>1;
            int nd=(i-mid)*a[i]-(sum[i-1]-sum[mid-1]);
            if(nd<=m){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans<<'\n';
    return 0;
}
