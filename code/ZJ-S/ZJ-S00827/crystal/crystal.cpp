#include<bits/stdc++.h>
using namespace std;
#define int long long
template<typename T> void Remax(T &a,T b){ a=max(a,b); }
template<typename T> void Remin(T &a,T b){ a=min(a,b); }
const int MAXN=5e5+10;
int n,m,a[MAXN],ans;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int sum=0;
    for(int i=1,j=1;i<=n;i++){
        while(j<i&&sum>m) sum-=a[i]-a[j++];
        Remax(ans,i-j+1);
        sum+=(i-j+1)*(a[i+1]-a[i]);
    } cout<<ans<<"\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int T=1;
//  cin>>T;
    while(T--) solve();
    return 0;
}