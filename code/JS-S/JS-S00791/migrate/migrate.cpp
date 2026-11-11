#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,d,a[N],L[N],R[N],szl[N],szr[N],sml[N],smr[N],cntl[N],cntr[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i],szl[i]=szr[i]=sml[i]=smr[i]=cntl[i]=cntr[i]=0;
    L[1]=1;cntl[1]++;
    for(int i=2;i<=n;i++){
        L[i]=L[i-1];
        while(a[i]-a[L[i]]>d) L[i]++;
        cntl[L[i]]++;
    }
    R[n]=n;cntr[n]++;
    for(int i=n-1;i>=1;i--){
        R[i]=R[i+1];
        while(a[R[i]]-a[i]>d) R[i]--;
        cntr[R[i]]++;
    }
    for(int i=1;i<=n;i++){
        szl[i]=cntr[i]+(R[i]!=i);
        if(L[i]<i&&R[L[i]]==i) szl[i]+=szl[L[i]]-1;
    }
    for(int i=n;i>=1;i--){
        szr[i]=cntl[i]+(L[i]!=i);
        if(R[i]>i&&L[R[i]]==i) szr[i]+=szr[R[i]]-1;
    }
    for(int i=1;i<=n;i++){
        smr[R[i]]+=(R[i]-i>=2);
        sml[L[i]]+=(i-L[i]>=2);
        if(R[i]-i>=2&&L[R[i]]==i&&L[R[i]-1]==i) smr[R[i]]+=szl[i]-1;
        if(i-L[i]>=2&&R[L[i]]==i&&R[L[i]+1]==i) sml[L[i]]+=szr[i]-1;
    }
    int ans=0;
    for(int i=2;i<n-1;i++)
        ans+=sml[i]*smr[i+1];
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int cid,T;cin>>cid>>T;
    while(T--) solve();
    return 0;
}