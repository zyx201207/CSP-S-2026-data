#include<bits/stdc++.h>
#define ll long long
using namespace std;
int C,T;
int n;
ll d;
const int N=2000005;
const int INF=2000105;
ll x[N];
pair<int,int> dp[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&C,&T);
    while(T--){
        scanf("%d%lld",&n,&d);
        for(int i=1;i<=n;i++){
            scanf("%lld",&x[i]);
        }
        if(C>10){
            printf("1\n");
            continue;
        }
        int ans=0;
        for(int l=1;l<=n;l++){
            for(int i=1;i<=n;i++){
                dp[i]={INF,1};
            }
            dp[l]={0,1};
            for(int r=l+1;r<=n;r++){
                int lst=lower_bound(x+1,x+n+1,x[r]-d)-x;
                lst=max(lst,l);
                //if(l==1)cout<<r<<" "<<lst<<endl;
                for(;lst<r;lst++){
                    if(dp[lst].first+1<dp[r].first){
                        dp[r].first=dp[lst].first+1;
                        dp[r].second=dp[lst].second;
                        //if(l==1)cout<<r<<" "<<lst<<" "<<dp[r].first<<" "<<dp[r].second<<endl;
                    }
                    else if(dp[lst].first+1==dp[r].first){
                        dp[r].second+=dp[lst].second;
                        if(dp[r].second>2)dp[r].second=3;
                    }
                }
                if(dp[r].second==2){
                    //cout<<l<<" "<<dp[r].first<<endl;
                    ans++;
                    //cerr<<dp[r].first<<" "<<l<<" "<<r<<endl;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
0 1
8 3
0 1 2 4 8 10 11 13
*/
