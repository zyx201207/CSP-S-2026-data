#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
int const N=2000006;
ll a[N];
ll f[N],g[N],p[N];
void solve(int c) {
    int n;
    ll d,ans=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(0<=c&&c<=10) {
        for(int i=1;i<=n;i++) {
            f[i]=0,g[i]=1,g[i-1]=0,p[0]=i;
            for(int l=i,j=i+1;j<=n;j++) {
                while(a[j]-a[l]>d) l++;
                if(l==j) {
                    f[j]=0,g[j]=g[j-1],p[0]=j;
                    continue;
                }
                f[j]=f[l]+1;
                int r=p[f[l]];
                g[j]=g[j-1]+(g[r]-g[l-1]);
                p[f[j]]=j;
            }
            for(int j=i+1;j<=n;j++) if(g[j]-g[j-1]==2) ans++;
//            for(int j=i+1;j<=n;j++) cout<<g[j]-g[j-1]<<' ';
//            cout<<endl;
        }
        cout<<ans<<endl;
        return;
    }
    if(11<=c&&c<=12) {
        int t=a[2]-a[1];
        if(n<=3) {
            cout<<0<<endl;
            return;
        }
        if(a[3]-a[1]>d) {
            cout<<0<<endl;
            return;
        }
        cout<<max(n-2*(d/(a[2]-a[1]))+1,0ll)<<endl;
        return;
    }
}
int main() {
#ifndef DEBUG
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
#endif // DEBUG
    int c,t;
    cin>>c>>t;
    while(t--) solve(c);
    return 0;
}
