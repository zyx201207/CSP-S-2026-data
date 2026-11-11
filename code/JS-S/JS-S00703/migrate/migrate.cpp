#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+5;
const int Inf=(int)(3e18)+7;
int c,tc;
int n,d;
int lst[maxn];
int a[maxn];
int f[maxn],g[maxn];
void AC(){
    for(int i=0;i<=n+3;i++){
        lst[i]=0;f[i]=Inf;g[i]=0;
    }
}
namespace subA{
    void solve(){
        int delta=a[2]-a[1];
        int len=d/delta;
        if(len<=1){
            cout<<"0\n";return;
        }
        cout<<max(0ll,n-2*len+1)<<'\n';
    }
}
namespace subB{
    void solve(){
        int ans=0;
        for(int i=1;i<=n;i++){
            int x=lst[i];
            if(x+1>=i) continue;
            int L=lst[x+1],R=x;
            if(x+2<i) R=lst[x+2];
            ans+=R-L;
        }
        cout<<ans<<'\n';
    }
}
void solve(){
    int ans=0;
    cin>>n>>d;AC();
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1){
        cout<<"0\n";return;
    }
    if(c==11||c==12){
        subA::solve();return;
    }
    lst[0]=1;
    for(int i=1;i<=n;i++){
        lst[i]=lst[i-1];
        while(lst[i]<i&&a[lst[i]]<a[i]-d) lst[i]++;
    }
    if(c==13||c==14){
        subB::solve();return;
    }
    /*cout<<"! ";
    for(int i=1;i<=n;i++) cout<<lst[i]<<' ';
    cout<<'\n';*/
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[j]=Inf;g[j]=0;
        }
        f[i]=0;g[i]=1;
        for(int j=i+1;j<=n;j++){
            if(lst[j]==j) break;
            int x=max(i,lst[j]);
            f[j]=f[x]+1;g[j]=g[x];
            if(x+1<j&&f[j]==f[x+1]+1) g[j]+=g[x+1];
            if(x+2<j&&f[j]==f[x+2]+1) g[j]+=g[x+2];
            g[j]=min(g[j],3ll);
            if(g[j]==2) ans++;
        }
        /*cout<<"// ";
        for(int j=i+1;j<=n;j++) cout<<g[j]<<' ';
        cout<<'\n';*/
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>tc;
    while(tc--) solve();
    return 0;
}