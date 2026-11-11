#include <bits/stdc++.h>
using namespace std;
int c,t,n,to[2000010],dis[2000010],cnt[2000010];
long long d,x[2000010],ans;
namespace BC {
    int a[2000010],b[2000010],c[2000010],pa[2000010],pb[2000010],pc[2000010];
    inline void solve() {
        for (int i=1;i<=n;++i) {
            a[i]=pa[i]=to[i];
            b[i]=pb[i]=min(i,to[i]+1);
            c[i]=pc[i]=min(i,to[i]+2);
        }
        for (int _=1;_<=20;++_) for (int i=1;i<=n;++i) {
            ans+=to[c[i]]-to[b[i]];
            c[i]=min({max(pa[b[i]],pb[a[i]]),pa[c[i]],pc[a[i]]});
            b[i]=min(pa[b[i]],pb[a[i]]);
            a[i]=pa[a[i]];
        }
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    for (int _=1;_<=t;++_) {
        cin>>n>>d;
        for (int i=1;i<=n;++i) cin>>x[i];
        for (int i=1,j=1;i<=n;++i) {
            while (x[i]-x[j]>d) ++j;
            to[i]=j;
        }
        ans=0;
        if (c>=11&&c<=12&&n>=2) {
            long long dt=x[2]-x[1];
            d/=dt;
            if (d>1) ans=max(0ll,n-2*d+1);
        }
        else if (c>=13&&c<=18) BC::solve();
        else for (int i=1;i<=n;++i) {
            dis[i]=0;
            cnt[i]=1;
            for (int j=i+1;j<=n&&to[j]<j;++j) if (to[j]<=i) dis[j]=1,cnt[j]=1;
            else {
                dis[j]=10000000;
                cnt[j]=0;
                for (int k:{to[j],to[j]+1,to[j]+2}) if (k<j&&dis[k]==dis[to[j]]) {
                    dis[j]=dis[k]+1;
                    cnt[j]+=cnt[k];
                }
                cnt[j]=min(cnt[j],3);
                if (cnt[j]==2) ++ans;
            }
        }
        cout<<ans<<'\n';
    }
}