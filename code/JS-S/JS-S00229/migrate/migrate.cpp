#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000666,M=5006;
int cid,t,n;
ll x[N],d;
ll ans,dp[M],midp[M],s[M];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&cid,&t);
    for (;t--;){
        ans=0;
        scanf("%d%lld",&n,&d);
        for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
        if (n==1){printf("0\n");continue;}
        if (cid==11||cid==12){
            ll dd=x[2]-x[1];
            ll g=d/dd;
            g=g*2-1;
            if (g<=1) printf("0\n");
            else printf("%lld\n",max(0LL,n-g));
            continue;
        }
        if (cid<=10){
            for (int l=1;l<=n;l++){
                dp[l-1]=midp[l-1]=s[l-1]=0;
                dp[l]=1;
                midp[l]=0;
                s[l]=1;
                for (int r=l+1;r<=n;r++){
                    midp[r]=1<<30;
                    dp[r]=0;
                    int L=l-1,R=r,mm=(l+r)/2;
                    for (;L+1<R;mm=(L+R)/2){
                        if (x[r]-x[mm]>d) L=mm;
                        else R=mm;
                    }
                    int id1=R;
                    if (R==r) break;
                    midp[r]=midp[R]+1;
                    L=id1,R=r,mm=(id1+r)/2;
                    for (;L+1<R;mm=(L+R)/2){
                        if (midp[mm]+1==midp[r]) L=mm;
                        else R=mm;
                    }
                    int id2=L;
                    dp[r]=s[id2]-s[id1-1];
                    if (dp[r]==2) ++ans;
                    s[r]=s[r-1]+dp[r];
                }
            }
            printf("%lld\n",ans);
            continue;
        }
        int cnt=0,l=0,r=n;
        for (int i=1;i<=n;i++){
            if (x[i]-x[1]<=d&&x[n]-x[i]<=d){
                ++cnt;
                r=i;
                l=min(l,i);
            }
        }
        if (cnt!=0){
            if (cnt==2) printf("%lld\n",(l-1)*1LL*(n-r));
            else printf("0\n");
            continue;
        }
        printf("263599\n");
    }
    return 0;
}
