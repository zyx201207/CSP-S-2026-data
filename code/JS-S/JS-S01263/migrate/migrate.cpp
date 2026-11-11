#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
const int N=2e6+5;
int n,mxr[N],mnl[N];
ll d,x[N];
// test 1-10
const int N1to10=5005;
int dis[N1to10],ri[N1to10];
ll cnt[N1to10],sum[N1to10];
void sol(){
    scanf("%d%lld",&n,&d);
    for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for(int i=1,j=0;i<=n;i++){
        // x[j+1]<=x[i]+d
        while(j<n&&x[j+1]-d<=x[i]){
            j++;
        }
        if(j<i) j=i;
        mxr[i]=j;
    }
    for(int i=1,j=1;i<=n;i++){
        while(mxr[j]<i) j++;
        mnl[i]=j;
    }
    if(n<=5000){
        // test 1-10 40pts
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<=n;j++) sum[j]=ri[j]=cnt[j]=0;
            cnt[i]=1;
            dis[i]=0;
            ri[0]=i;
            sum[i]=1;
            int lst=0;
            for(int j=i+1;j<=n;j++){
                if(mnl[j]==j){
                    break;
                }
                dis[j]=dis[mnl[j]]+1;
                if(dis[j]>lst){
                    ri[lst]=j-1;
                    lst=dis[j];
                }
                int l=mnl[j],r=ri[dis[mnl[j]]];
                cnt[j]=sum[r]-sum[l-1];
                sum[j]=sum[j-1]+cnt[j];
                assert(sum[j]>=0);
                if(cnt[j]==2) ans++;
            }
        }
        printf("%d\n",ans);
        return;
    }
    printf("0\n");
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    while(t--){
        sol();
    }
    return 0;
}

