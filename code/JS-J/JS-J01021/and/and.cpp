#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=-1;int a[N];
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=1;i<=n-m+1;i++){
        int t=a[i];
        for(int j=i;j<=i+m-1;j++)t&=a[j];
        ans=max(ans,t);
    }
    cout<<ans;
    return 0;
}
