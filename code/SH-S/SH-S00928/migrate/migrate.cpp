#include<bits/stdc++.h>
using namespace std;
const int N=2000010; long long a[N];
namespace Brute {
    int pre[N],dis[N]; long long num[N],sum[N];
    void solve() {
        int n; long long d; cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i],pre[i]=lower_bound(a+1,a+i+1,a[i]-d)-a;
        long long res=0;
        for(int i=1;i<=n;i++) {
            dis[i]=0,num[i]=sum[i]=1,sum[i-1]=0;
            for(int j=i+1;j<=n;j++) {
                int lst=max(pre[j],i);
                dis[j]=dis[lst]+1;
                int l=lst,r=j-1,ans=lst;
                while(l<=r) {
                    int mid=(l+r)>>1;
                    if(dis[mid]==dis[lst]) ans=mid,l=mid+1;
                    else r=mid-1;
                }
                num[j]=sum[ans]-sum[lst-1],sum[j]=sum[j-1]+num[j];
                if(num[j]==2) res++;
                //if(num[j]==2) cerr<<dis[j]<<'\n';
            }
        }
        cout<<res<<'\n';
    }
}
namespace SA {
    void solve() {
        int n; long long d; cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        if(n==1) cout<<"0\n";
        else {
            long long k=d/(a[2]-a[1]);
            if(k>1) cout<<max(0ll,n-2*k+1)<<'\n';
            else cout<<"0\n";
        }
    }
}
namespace SpecialB {
    int nxt[N];
    void solve() {
        int n; long long d; cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) nxt[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
        long long ans=0; int p=0;
        for(int i=1;i<=n;i++) if(max(a[n]-a[i],a[i]-a[1])<=d) { p=i; break; }
        //cout<<p<<'\n';
        for(int i=1;i<p;i++) if(nxt[i]==p+1) ans+=nxt[p+1]-p-1;
        cout<<ans<<'\n';
    }
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    int c,t; cin>>c>>t;
    if(c==11||c==12) while(t--) SA::solve();
    else if(c==13||c==14) while(t--) SpecialB::solve();
    else while(t--) Brute::solve();
    return 0;
}
