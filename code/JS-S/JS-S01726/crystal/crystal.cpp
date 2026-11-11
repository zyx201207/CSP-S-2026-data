#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+100;
int n,a[N],m,sum[N],ans=-1;
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int p=1;
    for(int i=1;i<=n;i++){
        sum[i]=a[i]+sum[i-1];
        while(p<=i&&(i-p+1)*a[i]-(sum[i]-sum[p-1])>m) p++;
        if((i-p+1)*a[i]-(sum[i]-sum[p-1])<=m) ans=max(ans,i-p+1);
    }
    cout<<ans;
    return 0;
}
