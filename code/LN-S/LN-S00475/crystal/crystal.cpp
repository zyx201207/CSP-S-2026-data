#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=-1e18;
int a[500005];
int sum[500005];
stack<int> st;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int j=n;
    for(int i=n;i>=1;i--){
        while(j>=1&&a[i]*(i-j+1)-(sum[i]-sum[j-1])<=m) j--;
        j++;
        ans=max(ans,i-j+1);
        j--;
    }
    cout<<ans;
    return 0;
}
