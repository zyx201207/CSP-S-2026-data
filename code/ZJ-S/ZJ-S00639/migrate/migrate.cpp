#include <bits/stdc++.h>
using namespace std;

namespace{
using ll=long long;
const int N=2e6+5;
ll x[N];int r[N],tag[N];
int f[N],g[N];
void solve(){
    int n;ll d;cin>>n>>d;
    for(int i=1;i<=n;i++)cin>>x[i];
    r[n]=n;
    for(int i=n-1;i;i--){
        r[i]=r[i+1];
        while(x[r[i]]>x[i]+d)--r[i];
    }
    tag[n]=n;
    for(int i=n-1;i;i--){
        tag[i]=i;
        if(r[r[i]-1]==r[r[i]]-1)tag[i]=tag[r[i]];
    }
    f[n]=0,g[n]=1;
    ll ans=0;
    for(int i=n-1;i;i--){
        if(r[r[i]-1]==r[i])f[i]=f[i+1],g[i]=g[i+1]+1;
        else if(r[i]-1==i+1||r[r[i]-2]!=r[r[i]-1]){
            if(r[r[i]]==r[r[i]-1])f[i]=g[r[i]]-(r[r[i]-2]-r[i]+1),g[i]=r[i]-i;
            else f[i]=f[r[i]-1]+g[r[i]-1],g[i]=g[r[i]]-(r[r[i]-1]-r[i])+(r[i]-i);
        }else{
            if(r[r[i]]==r[r[i]-1])f[i]=0,g[i]=r[i]-i;
            else{
                if(r[r[i]-1]<r[r[i]]-1)f[i]=f[r[i]];
                else if(r[r[r[i]-1]]==r[r[i]])f[i]=f[r[r[i]]];
                else{
                    int t=tag[r[i]];
                    if(r[r[t]-1]==r[r[t]])f[i]=0;
                    else f[i]=f[r[t]];
                }
                g[i]=g[r[i]]-(r[r[i]-1]-r[i])+(r[i]-i);
            }
        }
        ans+=f[i];
    }
    cout<<ans<<'\n';
    // for(int i=1;i<=n;i++)cout<<"f"<<i<<":"<<f[i]<<'\n';
    // for(int i=1;i<=n;i++)cout<<"g"<<i<<":"<<g[i]<<'\n';
}
}


int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin.tie(0),cout.tie(0);
    ios::sync_with_stdio(false);
    int C,_;cin>>C>>_;
    while(_--)solve();
    return 0;
}