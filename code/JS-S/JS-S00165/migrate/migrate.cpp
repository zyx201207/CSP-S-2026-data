#include <bits/stdc++.h>
using namespace std;
int c,t;
int n;
long long d,x[2000010];
int nxt[2000010],prv[2000010]; // Next and previous furtherest reachable island
long long prvp[2000010],nxtp[2000010]; // Previous and next single path count
bool prvpc[2000010],nxtpc[2000010]; // Previous and next uncovered check
void solve(){
    int j=1;
    for(int i=2;i<=n;i++){
        while(x[i]-x[j]>d){
            nxt[j]=i-1;
            j++;
        }
        prv[i]=j;
    }
    for(;j<=n;j++)nxt[j]=n;
    prvp[1]=nxtp[n]=prvp[n]=nxtp[1]=0;
    for(int i=2;i<n;i++){
        if(prv[i+1]==prv[i]){
            prvp[i]=0;
            continue;
        }
        prvp[i]=prv[i+1]-prv[i];
        prvp[i]+=prvp[prv[i]];
        if(nxt[i-1]>=nxt[i]-1)prvpc[i]=0;
        else prvpc[i]=1;
    }
    for(int i=n-1;i>1;i--){
        if(nxt[i-1]==nxt[i]){
            nxtp[i]=0;
            continue;
        }
        nxtp[i]=nxt[i]-nxt[i-1];
        nxtp[i]+=nxtp[nxt[i]];
        if(prv[i+1]<=prv[i]+1)nxtpc[i]=0;
        else nxtpc[i]=1;
    }
    long long ans=0;int k=0;
    for(int i=1;i<=n-3;i++){
        // Minimum Double-Path Island Pair
        int r=nxt[i];
        int s=nxt[r-1];
        k=max(k,r+1);
        while(k<=s){
            if(prv[k]!=r-1){
                k++;
                continue;
            }
            ans+=(prvpc[i]*prvp[i]+1)*(nxtpc[k]*nxtp[k]+1);
            k++;
        }
        k--;
    }
    cout<<ans<<endl;
}
int main(){
    !freopen("migrate.in","r",stdin);
    !freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            !scanf("%lld",x+i);
            nxt[i]=prv[i]=i;
        }
        solve();
    }
    return 0;
}