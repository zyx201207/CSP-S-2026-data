#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;
int n,d;
int a[N],R[N],r[N];
int cu_tb[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i],R[i]=0,r[i]=0;
    R[0]=1,r[n+1]=0,a[n+1]=-1e18;
    int ans=0;
    for(int i=1;i<=n;i++){
        R[i]=R[i-1];
        while(a[R[i]]-a[i]<=d&&R[i]<=n) R[i]++;
        R[i]--;
    }
    int sum=0;
    for(int i=n;i>=2;i--){
        if(R[i-1]==i&&R[i-2]!=i){
            if(r[i+1]) r[i]=r[i+1];
            else r[i]=i;
        }
    }
    for(int i=1;i<=n;i++) {
        // cout<<R[i];
        if(R[i]>=i+2){
            // int rr=1;
            // if(r[])
            ans+=(R[R[i]-1]-R[R[i]-2])*(1+sum)*(1+max(r[R[R[i]]+1]-R[R[i]],0ll));
            // cout<<i<<' ';
            // if(i==1) cout<<r[R[R[i]]+1]<<'-'<<R[R[i]];
            // cout<<r[R[R[i]]+1]<<'!'<<R[R[i]]<<"!"<<'\n';
        }
        // cout<<i<<'-'<<ans<<'\n'; 
            // cout<<sum<<"-"<<ans<<"!";
        if(R[i]==i+1) {sum++;}
        else sum=0;
        
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;cin>>C>>T;
    while(T--) solve();
    return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


0 1
5 3
-3 0 2 3 4

0 1
10 22
0 7 14 21 28 35 42 49 56 63

5
6
*/