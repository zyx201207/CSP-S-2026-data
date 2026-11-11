#include <bits/stdc++.h>
#define ll long long 
#define sc scanf 
#define pr printf
#define v1 first 
#define v2 second 
#define IINF 0x3f3f3f3f 
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
const int N=2e6+5;
ll a[N];
int nxt[N];
int lst[N];
ll dp[N][2];int fst[N],ed[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int _,t;sc("%d%d",&_,&t);
    while(t--){
        int n;ll d;
        sc("%d%lld",&n,&d);
        for(int i=1; i <= n; i++)sc("%lld",&a[i]),fst[i]=0,ed[i]=-1;
        for(int l=1,r=1;l<=n;l++){
            while(r<n&&a[r+1]-a[l]<=d)++r;
            nxt[l]=r;
            if(!fst[r])fst[r]=l;
            ed[r]=l;
        }
        for(int l=n,r=n;r>=1; r--){
            while(l>1&&a[r]-a[l-1]<=d)--l;
            lst[r]=l;
        }
        ll ans=0;
        for(int i=1; i <= n; i++)dp[i][0]=dp[i][1]=0;
        for(int i=1; i <= n; i++){
            //calc ans
            //from lst
            if(lst[i]==i){
                dp[i][0]=1;continue;
            }
            if(lst[i]<i){
                ans+=dp[lst[i]][1];
            }
            if(lst[i]+1<i){
                int ob=lst[i];
                // if(lst[ob+1]<ob){
                    ans+=dp[lst[i]+1][0]-1;
                    int cur=lst[ob+1];
                    // if(nxt[lst[ob+1]]==ob+1){
                    //     ans+=dp[lst[ob+1]][0];++cur;
                    // }
                    // ans+=max(0,min(ob-1,ed[ob+1])-max(cur+1,fst[ob+1])+1);
                    // for(int l=cur+1; l < ob; l++)ans+=nxt[l]==ob+1;
                // }
            }
            dp[i][0]+=1;
            if(nxt[lst[i]]==i){
                dp[i][0]+=dp[lst[i]][0],dp[i][1]+=dp[lst[i]][1];
                if(lst[i]+1<i){
                    int ob=lst[i];
                    // if(lst[ob+1]<ob){
                        // dp[i][1]-=dp[ob+1][1]-1;
                        dp[i][1]+=dp[ob+1][0]-1;
                        // dp[i][0]-=dp[ob+1][0]-1;
                        // int cur=lst[ob+1];
                //         if(nxt[lst[ob+1]]==ob+1){
                //             dp[i][1]+=dp[lst[ob+1]][0];++cur;
                //         }
                        // dp[i][1]+=max(0,min(ob-1,ed[ob+1])-max(cur+1,fst[ob+1])+1);
                        // for(int l=cur+1; l < ob; l++)dp[i][1]+=nxt[l]==ob+1;
                        // for(int l=lst[ob]+1; l < ob; l++)dp[i][0]+=nxt[l]==ob;
                        // dp[i][0]+=max(0,min(ob-1,ed[ob])-max(lst[ob]+1,fst[ob])+1);
                    // }
                }
                dp[i][0]+=max(0,min(i-1,ed[i])-max(lst[i]+1,fst[i])+1);
                // for(int l=lst[i]+1; l < i; l++)if(nxt[l]==i)dp[i][0]+=nxt[l]==i;
            }
            else {
                dp[i][0]+=max(0,min(i-1,ed[i])-max(lst[i],fst[i])+1);
                // for(int l=lst[i]; l < i; l++)if(nxt[l]==i)dp[i][0]+=nxt[l]==i;
            }
        }
        // for(int i=n-50; i <=n; i++)cerr<<dp[i][0]<<" "<<dp[i][1]<<endl;
        pr("%lld\n",ans);
    }
    return 0;
}
/*

6 4
-3 0 1 2 3 4
*/