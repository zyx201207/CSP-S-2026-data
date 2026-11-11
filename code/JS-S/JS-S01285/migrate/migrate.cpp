#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2000010;
int n;
ll d;
ll a[N];ll f[N];
int rgt[N],lft[N];
int L[N],R[N],gxL[N],gxR[N];
void solve(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) L[i]=R[i]=0,gxR[i]=gxL[i]=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        rgt[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
        lft[i]=lower_bound(a+1,a+1+n,a[i]-d)-a;
        // cout<<i<<' '<<rgt[i]<<' '<<lft[i]<<endl;
    }
    int l=1;
    for(int i=1;i<=n;i++){
        if(rgt[i]>i) L[rgt[i]]+=L[i]+1,gxL[i]+=L[i]+1;
        if(rgt[i]==rgt[i-1]) L[rgt[i]]-=L[i],gxL[i]-=L[i];
    }
    int r=n;
    for(int i=n;i>=1;i--){
        if(lft[i]<i) R[lft[i]]+=R[i]+1,gxR[i]+=R[i]+1;
        if(lft[i]==lft[i+1]) R[lft[i]]-=R[i],gxR[i]-=R[i];
    }
    ll ans=0;
    for(int i=3;i<n;i++){
        if(abs(a[i]-a[i-1])<=d){
            ll ansl=R[i-1],ansr=L[i];
            if(rgt[i-1]==i) ansr=ansr-(gxL[i-1]);
            if(lft[i]==i-1) ansl=ansl-(gxR[i]);
            ans+=ansl*ansr;
            // cout<<L[i]<<' '<<R[i-1]<<endl;
            // cout<<i<<' '<<ansl<<' '<<ansr<<endl;
        }
        // cout<<i<<' '<<L[i]<<' '<<R[i-1]<<endl;
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) solve();
    return 0;
}
/*
0 1
10 22
0 7 14 21 28 35 42 49 56 63

*/