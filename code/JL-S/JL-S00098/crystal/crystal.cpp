#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
#define int long long
int a[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,ans=0,r=0,sum=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int l=1;l<=n;l++){
        sum-=a[r]-a[l-1];
        while(r<n&&sum+(r-l+1)*(a[r+1]-a[r])<=m)sum+=(r-l+1)*(a[r+1]-a[r]),r++;
        ans=max(ans,r-l+1);
    }
    cout<<ans<<endl;
    return 0;
}