#include<bits/stdc++.h>
#define int long long
#define REP(i,a,b,c) for(int i=a;i<=b;i+=c)
#define PER(i,a,b,c) for(int i=a;i>=b;i-=c)
#define sz(s) s.size()
using namespace std;
const int N=5e5+5;
int n,m,a[N],d[N],prefix[N];
bool check(int x){
    int k=x-1;
    REP(i,x,n,1)
        if(k*a[i]-prefix[i-1]+prefix[i-x]<=m) return 1;
    return 0;
}
void solve(){
    cin>>n>>m;
    REP(i,1,n,1) cin>>a[i];
    sort(a+1,a+n+1);
    REP(i,1,n,1) prefix[i]=prefix[i-1]+a[i];
    int l=2,r=5e5,ans=1;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) l=mid+1,ans=mid;
        else r=mid-1;
    }
    cout<<min(n,ans);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    solve();
}
