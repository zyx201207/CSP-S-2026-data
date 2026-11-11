#include <bits/stdc++.h>
using namespace std;
long long x[2000006];
int pre[2000006],nxt[2000006];
int L[2000006],R[2000006];
int valL[2000006],valR[2000006];
void solve(){
    int n;
    long long d;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        L[i]=R[i]=0;
        valL[i]=valR[i]=0;
    }
    for(int i=1,j=1;i<=n;i++){
        while(x[i]-x[j]>d)j++;
        pre[i]=j;
        R[j]++;
    }
    for(int i=n,j=n;i;i--){
        while(x[j]-x[i]>d)j--;
        nxt[i]=j;
        L[j]++;
    }
    for(int i=1;i<=n;i++){
        if(pre[i]!=i&&nxt[pre[i]]==i){
            L[i]+=L[pre[i]];
        }
    }
    for(int i=n;i;i--){
        if(nxt[i]!=i&&pre[nxt[i]]==i){
            R[i]+=R[nxt[i]];
        }
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        if(nxt[i]>=i+2){
            valL[nxt[i]]+=1;
            if(pre[nxt[i]-1]==i){
                valL[nxt[i]]+=L[i];
            }
        }
        if(pre[i]<=i-2){
            valR[pre[i]]+=1;
            if(nxt[pre[i]+1]==i){
                valR[pre[i]]+=R[i];
            }
        }
    }
    for(int i=2;i<=n;i++){
        ans+=1ll*valL[i]*valR[i-1];
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}