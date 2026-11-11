#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500006;
int a[N],b[N];
int n,m;
void solve(){
    int l=1,r=1;
    int sum=0,cnt=1;
    int ans=-1;
    while(r<=n&&l<=r){
        if(sum<=m){
            ans=max(ans,cnt);
            cnt++;
            sum+=(r-l+1)*b[r++];
        }
        else{
            cnt--;
            sum-=a[r]-a[l++];
        }
    }
    cout<<ans;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
    solve();
    return 0;
}//37min
