#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N],sum[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cout.tie(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int i=1;
    int ans=0;
    for(int j=1;j<=n;j++){
        while((j-i+1)*a[j]-(sum[j]-sum[i-1])>m)i++;
        ans=max(ans,j-i+1);
    }
    cout<<ans;
    return 0;
}
