#include<bits/stdc++.h>
using namespace std;
const int N=2000005,inf=0x3f3f3f3f;
long long a[N],d;
int n;
namespace jiasuan{
    long long sum[N][2];
    int nxt[N],num[N][2],dp[N];
    bool check(int i,int j){
        const int L=max(i+1,int(lower_bound(a,a+n,a[j]-d)-a));
        const int R=min(j,int(upper_bound(a,a+n,a[i]+d)-a));
        return (R-L==2);
    }
    void solve(){
        for(int i=0;i<n;++i){
            nxt[i]=int(upper_bound(a,a+n,a[i]+d)-a)-1;
            if(nxt[i]==i) nxt[i]=-1;
        }
        for(int u=0;u<n;++u){
            num[u][0]=num[u][1]=0;
            if(nxt[u]==-1 || nxt[nxt[u]]==-1) continue;
            const int pos=int(upper_bound(a,a+n,a[u]+d)-a)-2;
            int L=nxt[u]+1,R=nxt[nxt[u]]+1;
            if(0<=pos && pos<=n){
                if(pos>0) L=max(L,int(upper_bound(a,a+n,a[pos-1]+d)-a));
                if(pos<n) R=min(R,int(upper_bound(a,a+n,a[pos]+d)-a));
            }else L=R=0;
            num[u][1]=max(0,R-L);
            num[u][0]=nxt[nxt[u]]-nxt[u]-num[u][1];
        }
        for(int u=n-1;u>=0;--u){
            for(int i=0;i<2;++i) sum[u][i]=num[u][i]+(nxt[u]==-1?0:sum[nxt[u]][i]);
        }
        for(int i=n-1;i>=0;--i){
            if(nxt[i]==-1 || nxt[nxt[i]]==-1 || nxt[nxt[nxt[i]]]==-1 || check(i,nxt[nxt[i]])) dp[i]=i;
            else if(nxt[i]==-1) dp[i]=-1;
            else dp[i]=dp[nxt[i]];
        }
        long long ans=0;
        for(int s=0;s<n;++s){
            if(nxt[s]==-1 || nxt[nxt[s]]==-1) continue;
            //i=[1,pos) tot=0
            //i=[pos,ppos) tot=1
            const int pos=dp[s];
            ans+=sum[s][1]-sum[nxt[pos]][1];
            if(nxt[pos]!=-1 && nxt[nxt[pos]]!=-1 && nxt[nxt[nxt[pos]]]!=-1){
                const int ppos=dp[nxt[pos]];
                ans+=sum[nxt[pos]][0]-sum[nxt[ppos]][0];
            }
        }
        cout << ans << '\n';
    }
}
namespace baoli{
    int dis[N],num[N],lst[N],sum[N];
    void solve(){
        long long ans=0;
        for(int s=0;s<n;++s){
            dis[s]=0;
            sum[s]=num[s]=1;
            int pos=s;
            lst[0]=s;
            for(int t=s+1;t<n;++t){
                while(pos<t && a[t]-a[pos]>d) ++pos;
                if(pos==t) break;
                dis[t]=dis[pos]+1;
                num[t]=min(3,sum[lst[dis[pos]]]-(pos==s?0:sum[pos-1]));
                lst[dis[t]]=t;
                sum[t]=sum[t-1]+num[t];
                if(num[t]==2) ++ans;
            }
        }
        cout << ans << '\n';
    }
}
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int Case,T;
    cin >> Case >> T;
    while(T--){
        cin >> n >> d;
        for(int i=0;i<n;++i) cin >> a[i];
        if(n<=5000) baoli::solve();
        else jiasuan::solve();
    }
    return 0;
}