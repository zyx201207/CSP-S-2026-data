#include<bits/stdc++.h>
using namespace std;
int c,t,n,st[2000005],ed[2000005],sum1[2000005],sum2[2000005];
long long d,x[2000005],cnt1[2000005],cnt2[2000005],ans,nxt;
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while (t--) {
        ans=0;
        scanf("%d%lld",&n,&d);
        for (int i=1;i<=n;i++) {
            cnt1[i]=cnt2[i]=st[i]=ed[i]=sum1[i]=sum2[i]=0;
            scanf("%lld",&x[i]);
        }
        nxt=1;
        for (int i=1;i<=n;i++) {
            while (nxt<n&&x[nxt+1]-x[i]<=d) nxt++;
            ed[i]=nxt;
        }
        nxt=n;
        for (int i=n;i;i--) {
            while (nxt>1&&x[i]-x[nxt-1]<=d) nxt--;
            st[i]=nxt;
        }
        for (int i=1;i<n;i++) sum1[i]=(st[i+1]==i+1?i:st[i+1])-st[i];
        for (int i=1;i<n;i++) {
            if (!sum1[i]) continue;
            sum1[i]=sum1[i]+sum1[st[i]];
        }
        for (int i=n;i>1;i--) sum2[i]=ed[i]-(ed[i-1]==i-1?i:ed[i-1]);
        for (int i=n;i>1;i--) {
            if (!sum2[i]) continue;
            sum2[i]=sum2[i]+sum2[ed[i]];
        }
        nxt=1;
        for (int i=1;i<=n;i++) {
            while (nxt<n&&x[nxt+1]-x[i]<=d) nxt++;
            if (nxt>i+1) cnt1[nxt]+=sum1[i]+1;
        }
        nxt=n;
        for (int i=n;i;i--) {
            while (nxt>1&&x[i]-x[nxt-1]<=d) nxt--;
            if (nxt<i-1) cnt2[nxt]+=sum2[i]+1;
        }
        for (int i=2;i<n-1;i++) ans+=cnt2[i]*cnt1[i+1];
        printf("%lld\n",ans);
    }
    return 0;
}
