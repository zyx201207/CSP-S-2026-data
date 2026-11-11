#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int a[N],p[N],dp[N][3],c[N][3],n,d,ans,f[N],dis[N],cnt[N];
inline void solve(){
    for (int i=1;i<=n;i++){
            dp[i][0]=dp[i][1]=dp[i][2]=0;
            c[i][0]=c[i][1]=c[i][2]=0;
            p[i]=max(p[i-1],i);
            while (p[i]<n&&a[p[i]+1]-a[i]<=d) p[i]++;
        }
        c[n+1][0]=c[n+1][1]=c[n+1][2]=0;
        int l1=1,l2=1;
        for (int i=1;i<=n;i++){
            c[i][0]+=c[i-1][0];
            c[i][1]+=c[i-1][1];
            c[i][2]+=c[i-1][2];
            dp[i][0]+=c[i][0];
            dp[i][1]+=c[i][1];
            dp[i][2]+=c[i][2];
            l1=max(l1,i+1),l2=max(l2,i+1);
            if (p[i]>i+1) dp[p[i]][0]++;
            else if (p[i]==i+1) dp[p[i]][1]++;
            if (i>1&&p[i]>i){
                while (l1<=p[i]&&a[l1]-a[i-1]<=d) l1++;
                if (l1<=p[i]&&a[p[i]]-a[i-1]>d){
                    ans+=(p[i]-l1)*dp[i][2];
                    dp[p[i]][2]+=dp[i][2];
                    if (p[i]>i+1) dp[p[i]][0]+=dp[i][0]+dp[i][1];
                    else if (p[i]==i+1) dp[p[i]][1]+=dp[i][0]+dp[i][1];
                }
            }
            if (i>2&&p[i-1]>i){
                while (l2<=p[i-1]&&a[l2]-a[i-2]<=d) l2++;
                if (l2<=p[i-1]&&a[p[i-1]]-a[i-2]>d){
                    ans+=(p[i-1]-l2)*dp[i][0];
                    dp[p[i-1]][2]+=dp[i][0];
                } 
            }
            ans+=dp[i][2];
        }
}
inline void baoli(){
    int p,pr;
    for (int l=1;l<=n;l++){
        p=l+1,pr=l;
        int cnt[3]={};
        for (int r=l+1;r<=n;r++){
            f[r]=0;
            if (a[r]-a[l]<=d){
                dis[r]=1;
                continue;
            }
            while (a[r]-a[p]>d) cnt[f[p]]--,p++;
            while (pr+1<r&&dis[pr+1]<=dis[p]) cnt[f[++pr]]++; 
            if (p==r) break;
            int k=cnt[0]+cnt[1]*2+cnt[2]*11;
            if (k>2) f[r]=2;
            if (k==2) f[r]=1,ans++; 
            dis[r]=dis[p]+1;
        }
    }
}
inline void qwq(){
    int k=d/(a[2]-a[1]);k=k*2;
    ans=max(n-k+1,0ll);
}
inline void solve_qwq(){
    for (int i=1;i<=n;i++){cnt[i]=0;
        p[i]=max(p[i-1],i);
        while (p[i]<n&&a[p[i]+1]-a[i]<=d) p[i]++;
    }
    int qwq=1;
    for (int i=1;i<=n;i++){
        while (a[i]-a[qwq]>d) qwq++;
        if (qwq+1<i) ans+=cnt[qwq+1];
        if (p[i]>i+1) cnt[p[i]]++;
    }
}
signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int gty,_;cin>>gty>>_;
    while (_--){
        cin>>n>>d;ans=0;
        for (int i=1;i<=n;i++){
            cin>>a[i];
        }
        if (gty<=10) baoli();
        else if (gty<=12) qwq();
        else if (gty<=14) solve_qwq(); 
        else solve();
        cout<<ans<<'\n';
    }
    return 0;
}