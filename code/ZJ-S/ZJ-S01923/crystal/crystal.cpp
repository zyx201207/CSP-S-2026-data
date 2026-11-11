#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,RN=5e5;
int T,n,m;
int a[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int sum=0,ans=0;
    for(int i=1,j=1;i<=n;i++){
        sum+=a[i]; 
        while(j<=i&&(a[i]*(i-j+1)-sum)>m){
            sum-=a[j];
            j++;
        }
        ans=max(ans,i-j+1);
    }
    cout<<ans<<'\n';
    return;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    T=1;
    while(T--){
        solve();
    }
    return 0;
}