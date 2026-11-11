#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i = 1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long ans = 1,l = 1;
    __int128 sum = 0;
    for(long long i = 2;i<=n;i++){
        sum+=(i-l)*(a[i]-a[i-1]);
        while(sum>m && l<i){
            sum-=(a[i]-a[l]);
            l++;
        }
        ans = max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
