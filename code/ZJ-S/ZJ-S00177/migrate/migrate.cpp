#include<iostream>
#include<cstdio>
#define int long long
#define PII pair<int,int>
using namespace std;
int c,t,n,d,a[2000005],ans[2000005][2],pre[2000005];
PII dp[5005];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i],ans[i][0]=ans[i][1]=pre[i]=0;
        // for(int i=1;i<=n;i++) cout<<a[i]-a[i-1]<<' ';cout<<'\n';
        int l=1;
        for(int i=1;i<=n;i++){
            while(a[i]-a[l]>d) l++;
            pre[i]=l;
        }
        if(n<=5000){
            int res=0;
            for(int i=1;i<=n;i++){
                int l=i,cnt=1;
                dp[i].first=0,dp[i].second=1;
                for(int j=i+1;j<=n;j++){
                    while(a[j]-a[l]>d){
                        if(l!=j-1&&dp[l].first!=dp[l+1].first){
                            cnt=0;
                            for(int k=l+1;k<j;k++){
                                if(dp[k].first!=dp[l+1].first) break;
                                cnt+=dp[k].second;
                            }
                            l++;
                        }else cnt-=dp[l].second,l++;
                    }
                    if(l==j) break;
                    if(cnt==2) res++;
                    dp[j]={dp[l].first+1,cnt};
                    // cout<<i<<' '<<j<<' '<<dp[j].first<<' '<<dp[j].second<<'\n';
                }
            }
            cout<<res<<'\n';
        }else{
            for(int i=1;i<=n;i++){
                int x=pre[i],y=pre[i]+1;
                if(pre[i]==i){
                    ans[i][0]=0;
                }else if(pre[i]==i-1){
                    ans[i][0]=ans[i-1][0]+1;
                }else{
                    ans[i][0]=i-pre[i];
                    if(pre[x]==pre[y]){
                        ans[i][0]+=0;
                    }else if(pre[x]==pre[y]-1){
                        ans[i][0]+=max(0ll,ans[pre[x]][0]+1-(pre[x]-pre[pre[y]]));
                    }else{
                        ans[i][0]+=ans[x][0]-(x-pre[x]-2);
                    }
                }
            }
            for(int i=1;i<=n;i++){
                int x=pre[i],y=pre[i]+1;
                if(pre[i]==i){
                    ans[i][1]=0;
                }else if(pre[i]==i-1){
                    ans[i][1]=ans[i-1][1];
                }else{
                    ans[i][1]=min(pre[x+2],x)-pre[y];
                    if(pre[x]==pre[y]){
                        if(min(pre[x+2],x)-pre[y]>0) ans[i][1]+=ans[x][0]-(x-pre[x]);
                    }else if(pre[x]==pre[y]-1){
                        ans[i][1]+=max(0ll,ans[pre[x]][1]-(pre[pre[x]]-pre[pre[pre[y]]]));
                    }else{
                        ans[i][1]+=ans[x][1];
                    }
                }
            }
        int res=0;
        for(int i=1;i<=n;i++) res+=ans[i][1];
        cout<<res<<'\n';
        }

        // for(int i=1;i<=n;i++) cout<<ans[i][0]<<' ';
        // cout<<'\n';
        // for(int i=1;i<=n;i++) cout<<ans[i][1]<<' ';
        // cout<<'\n';
    }
    return 0;
}