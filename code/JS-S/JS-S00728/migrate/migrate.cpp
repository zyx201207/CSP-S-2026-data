#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int M=2000006;
int n;
ll d;
ll a[M];
int R[M],L[M];
int cntL[M],cntR[M];
int rcnt[M],lcnt[M];
void solve(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++)lcnt[i]=rcnt[i]=0;
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int i=1,r=1;i<=n;i++){
        while(r<n&&a[r+1]-a[i]<=d)r++;
        R[i]=r;
        if(i!=r)rcnt[r]++;
    }
    for(int i=n,l=n;i;i--){
        while(l>1&&a[i]-a[l-1]<=d)l--;
        L[i]=l;
        if(i!=l)lcnt[l]++;
    }
    for(int i=1;i<=n;i++){
        if(R[L[i]]==i&&i!=L[i])cntL[i]=cntL[L[i]]+rcnt[i];
        else cntL[i]=rcnt[i];
    }
    for(int i=n;i;i--){
        if(L[R[i]]==i&&i!=R[i])cntR[i]=cntR[R[i]]+lcnt[i];
        else cntR[i]=lcnt[i];
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        if(R[i]-i<2)continue;
        ll lef=L[R[i]-1]==i?cntL[i]+1:1;
        if(R[R[i]-1]<=R[i])continue;
        ll rit=R[R[i]-1]-R[R[i]-2]+(L[R[R[i]]]==R[i]-1?cntR[R[R[i]]]:0);
        ans+=lef*rit;
    }
    printf("%lld\n",ans);
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    scanf("%*d%d",&t);
    while(t--)solve();
    return 0;
}