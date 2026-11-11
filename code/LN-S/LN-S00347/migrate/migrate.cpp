#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int N=3e3+10;
int n,m,a[N],f[N],g[N],ans;
void check(int l,int r){
    memset(f,0x3f,sizeof(f));memset(g,0,sizeof(g));
    f[l]=0;g[l]=1;
    int pos=l;
    for(int i=l+1;i<=r;i++){
        while(a[i]-a[pos]>m) pos++;
        if(pos>=i) return ;
        for(int j=pos;j<i;j++){
            f[i]=min(f[i],f[j]+1);
        }
        for(int j=pos;j<i;j++){
            if(f[j]+1==f[i]) g[i]+=g[j];
        }
        if(g[i]==2) ans++;
    }
}
void solve(){
    cin>>n>>m;
    ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        check(i,n);
    }
    cout<<ans<<'\n';
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int c,t;cin>>c>>t;
    for(int _=1;_<=t;_++) solve();
    return 0;
}