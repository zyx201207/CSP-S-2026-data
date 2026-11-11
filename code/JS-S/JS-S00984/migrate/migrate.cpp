#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int n,a[N],m,nxt[N],tp[N],pre[N],s1[N],s2[N];
int lp[N],rp[N];
// int gettyp(int x,int y,int z){
//     if(y==x+1)return 0;
//     if(a[z]-a[y-1]>m)return 0;
//     if(y==x+2)return 1;
//     if(a[z]-a[y-2]>m)return 1;
//     return 2;
// }
// int cal(int x,int t){
//     int y=nxt[x],z=nxt[y];
//     if(!z)return 0;
//     if(!t){
//         if(y==x+1)return z-y-1;
//         int tmp=nxt[y-1];
//         if(tmp==z)return 0;
//         return z-tmp-1;
//     }
//     else{
//         if(y==x+1)return 0;
//         int tmp=nxt[y-1];
//         tmp=min(tmp,z-1);
//         if(y==x+2||nxt[y-2]==y-1)return tmp-y;
//         int tmp2=nxt[y-2];
//         return max(0ll,tmp-tmp2);
//     }
// }
// int Nxt[N],suf[N],suf2[N];
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i],s1[i]=s2[i]=0,lp[i]=n+1,rp[i]=0;
    for(int j=1,i=1;i<=n;i++){
        while(j<i&&a[i]-a[j]>m)j++;
        if(j<i)pre[i]=j,lp[pre[i]]=min(lp[pre[i]],i),rp[j]=i;
        else pre[i]=0;
    }
    for(int j=n,i=n;i;i--){
        while(j>i&&a[j]-a[i]>m)j--;
        if(j>i)nxt[i]=j;
        else nxt[i]=0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        s1[i]++;
        // if(nxt[i])s1[nxt[i]]++;
        if(nxt[i]&&pre[nxt[i]]==i)s1[nxt[i]]+=s1[i];
        else if(nxt[i])s1[nxt[i]]++;
    }
    for(int i=n;i;i--){
        s2[i]++;
        if(pre[i]&&nxt[pre[i]]==i)s2[pre[i]]+=s2[i];
        else if(pre[i])s2[pre[i]]++;
    }
    // for(int i=3;i<n;i++){
    //     if(nxt[i]&&pre[nxt[i]]==i-1&&pre[i-1]&&nxt[pre[i-1]]==i){
    //         ans+=s1[pre[i-1]]*s2[nxt[i]];
    //     }
    // }
    for(int i=1;i<n;i++){
        if(nxt[i]&&pre[nxt[i]-1]==i){
            int t=nxt[i];
            if(nxt[t]&&pre[nxt[t]]==t-1)ans+=s1[i]*s2[nxt[t]];
            // else{
                int L=t+1,R=nxt[t]?nxt[t]-1:n;
                L=max(L,lp[t-1]),R=min(R,rp[t-1]);
                if(L<=R)ans+=s1[i]*(R-L+1);
            // }
        }
        else if(nxt[i]){
            int t=nxt[i];
            if(nxt[t]&&pre[nxt[t]]==t-1){
                ans+=s2[nxt[t]];
                // cout<<i<<' '<<ans<<'\n';
            }
            // else{
                int L=t+1,R=nxt[t]?nxt[t]-1:n;
                L=max(L,lp[t-1]),R=min(R,rp[t-1]);
                // int L2=pre[t-1]+1,R2=t-2;
                // L2=max(L2,ln[t]),R2=min(R2,rn[t]);
                if(L<=R)ans+=(R-L+1);
                // cout<<i<<' '<<ans<<'\n';
            // }
        }
        // cout<<i<<' '<<ans<<'\n';
    }
    // for(int i=n;i;i--)if(nxt[nxt[i]]){
    //     tp[i]=gettyp(i,nxt[i],nxt[nxt[i]]);
    //     // int ps=i;
    //     // while(tp[ps]!=1){
    //     //     if(tp[ps]==2||tp[ps]==-1)break;
    //     //     ps=nxt[ps];
    //     // }
    //     if(tp[i]!=0)Nxt[i]=i,suf[i]=suf2[i]=0;
    //     else Nxt[i]=Nxt[nxt[i]],suf[i]=cal(i,0)+1+suf[nxt[i]],suf2[i]=suf2[nxt[i]]+cal(nxt[i],1);
    //     int ps=Nxt[i];
    //     if(tp[ps]==1){
    //         ans+=1+suf[nxt[ps]];
    //         // while(1){
    //         //     ps=nxt[ps];
    //         //     if(tp[ps]!=0)break;
    //         //     ans+=cal(ps,0)+1;
    //         // }
    //     }
    //     ps=i;
    //     ans+=cal(i,1)+suf2[i];
    //     // while(tp[ps]==0){
    //     //     ps=nxt[ps];
    //     //     if(nxt[nxt[ps]])ans+=cal(ps,1);
    //     // }
    //     cout<<i<<' '<<ans<<' '<<cal(i,1)<<' '<<cal(i,0)<<'\n';
    // }else tp[i]=-1,Nxt[i]=i,suf[i]=suf2[i]=0;
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cc,tc;
    cin>>cc>>tc;
    while(tc--)solve();
    return 0;
}
/*
0 1
10 21
0 7 14 21 28 35 42 49 56 63
*/