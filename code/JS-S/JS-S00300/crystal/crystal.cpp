#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],d[N],ans=1,l=1,r=1,sum=0;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        r=i;
        sum+=(r-l)*(a[i]-a[i-1]);
        while(sum>m){
            l++;sum-=(a[i]-a[l]);
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
