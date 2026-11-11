#include<bits/stdc++.h>
#define int long long
#define arr array<int,2>
using namespace std;
const int N=5005,F=1e18;
int C,T,n,d,x[N];
int f[N],g[N],h[N],s[N];
void solve(){
    cin>>n>>d;int ans=0;
    for(int i=1;i<=n;++i)
        cin>>x[i];
    for(int i=1;i<=n;++i){
        f[i]=0,g[i]=s[i]=1,h[0]=i;
        for(int j=i+1,k=i;j<=n;++j){
            while(x[j]-x[k]>d)++k;
            if(k==j)break;
            f[j]=f[k]+1,h[f[j]]=j;
        }
        for(int j=i+1,k=i;j<=n;++j){
            if(!f[j])break;
            while(x[j]-x[k]>d)++k;
            g[j]=s[h[f[j]-1]]-s[k-1];
            ans+=(g[j]==2);
            g[j]=min(g[j],1000000ll);
            s[j]=s[j-1]+g[j];
        }for(int j=i;j<=n;++j)f[j]=g[j]=s[j]=0;
        for(int j=0;j<=n;++j)h[j]=0;
    }cout<<ans<<'\n';
}signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    for(cin>>C>>T;T;--T)solve();
    return 0;
}