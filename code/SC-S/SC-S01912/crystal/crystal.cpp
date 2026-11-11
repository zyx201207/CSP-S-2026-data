#include<bits/stdc++.h>
using namespace std;
#ifdef DEBUG
#define dbgblk if(1)
#else
#define dbgblk if(0)
#endif
#define dbg (cerr<<"["<<__LINE__<<"]:")
const int N=5e5+5;
using ll=long long;
int n;ll m;
array<ll,N>a;
int main(){
    freopen("crystal.in","r",stdin);
    dbgblk{freopen("crystal.err","w",stderr);}
    freopen("crystal.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    sort(a.begin()+1,a.begin()+n+1,greater<>());
    int r=0,ans=0;ll sum=0;
    for(int l=1;l<=n;++l){
        while(r<n&&a[l]*(r-l+2)-(sum+a[r+1])<=m)++r,sum+=a[r];
        ans=max(ans,r-l+1);
        sum-=a[l];
    }
    cout<<ans<<'\n';
    return 0;
}