#include<bits/stdc++.h>
using namespace std;
long long a[500005],pre[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n,m,ans=0;
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
    for(long long i=1,j=1;i<=n;i++){
        while(j<i&&a[i]*(i-j+1)-pre[i]+pre[j-1]>m) j++;
        //cerr<<i<<" "<<j<<"\n";
        long long tool=i-j+1;
        ans=max(ans,tool);
    }
    cout<<ans;
    return 0;
}
