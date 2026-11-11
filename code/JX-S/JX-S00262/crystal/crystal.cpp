#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;
ll n,m,a[N],dp[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    ll sum=0;
    for(int i=1;i<n;i++) sum+=a[n]-a[i];
    if(sum<=m){
        cout<<n;
        return 0;
    }
    dp[1]=0;
    for(int i=2;i<=n;i++){
        for(int j=i-1;j>=1;j--){
            dp[i]+=a[i]-a[j];
        }
    }
    for(int i=1;i<=n;i++){
        if(dp[i]>m){
            cout<<i-1;
            break;
        }
    }
    return 0;
}
