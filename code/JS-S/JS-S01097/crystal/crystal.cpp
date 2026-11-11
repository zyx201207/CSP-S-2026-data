#include <bits/stdc++.h>
using namespace std;
namespace chennie_bless_me{
typedef long long ll;
typedef long double ld;
typedef __int128 i128;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<typename T>
inline void chmax(T &a,T b){
    if(a<b) a=b;
}
template<typename T>
inline void chmin(T &a,T b){
    if(b<a) a=b;
}
const int N=5e5+5;
ll a[N],n,m;
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int ans=0; ll sum=a[n];
    for(int i=n,j=n;i>=1;i--){
        for(;j>=1&&(i-j+1)*a[i]-sum<=m;j--){
            sum+=a[j-1];
        }
        sum-=a[i];
        chmax(ans,i-j);
    }
    cout<<ans<<'\n';
}
void main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
}
int main(){
    assert(freopen("crystal.in","r",stdin));
    assert(freopen("crystal.out","w",stdout));
    chennie_bless_me::main();
    return 0;
}