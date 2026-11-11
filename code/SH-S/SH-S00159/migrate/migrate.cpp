#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
const int MAXN=2e6+5;
vector<int> vc;
int n;
ll d,ans=0;
ll a[MAXN];
int dp[MAXN];
int ne[MAXN];
void solve(int l,int r){
    // cerr<<"solve:"<<l<<" "<<r<<"\n";
    for(int i=l;i<=r;i++){
        dp[i-1]=0;
        // for(int j=i;j<=ne[i];j++){
        //     dp[j]=1;
        // }
        for(int j=0;j<3;j++){
            if(ne[i]-j>=i){
                dp[ne[i]-j]=1;
            }
        }
        int j=ne[i];
        while(j<r){
            // cerr<<"###"<<j<<" "<<ne[j]<<"\n";
            // for(int k=j+1;k<=ne[j];k++){
            //     int tmp=dp[j];
            //     if(ne[j-1]>=k){
            //         tmp+=dp[j-1];
            //     }
            //     if(ne[j-2]>=k){
            //         tmp+=dp[j-2];
            //     }
            //     ans+=(tmp==2);
            // }
            if(dp[j]==2){
                ans+=max(0,ne[j]-max(ne[j-1]+1,j+1)+1);
            }
            if(dp[j]+dp[j-1]==2){
                ans+=max(0,ne[j-1]-max(j+1,ne[j-2]+1)+1);
            }
            // for(int k=max(ne[j-1]+1,j+1);k<=ne[j];k++){
            //     ans+=(dp[j]==2);
            // }
            // for(int k=max(j+1,ne[j-2]+1);k<=ne[j-1];k++){
            //     ans+=(dp[j]+dp[j-1]==2);
            // }
            for(int k=max(j+1,ne[j]-2);k<=ne[j];k++){
                dp[k]=dp[j];
                if(ne[j-1]>=k){
                    dp[k]+=dp[j-1];
                }
                if(ne[j-2]>=k){
                    dp[k]+=dp[j-2];
                }
                dp[k]=min(dp[k],3);
            }
            j=ne[j];
            if(dp[j]>=3){
                break;
            }
        }
    }
}
void solve(){
    ans=0;
    vc.clear();
    scanf("%d %lld",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    vc.push_back(1);
    for(int i=1;i<=n;i++){
        ne[i]=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
        if((i==n)||(a[i+1]-a[i]>d)){
            vc.push_back(i+1);
        }
        // cerr<<"ne["<<i<<"]:"<<ne[i]<<"\n";
    }
    for(int i=0;i<vc.size()-1;i++){
        solve(vc[i],vc[i+1]-1);
    }
    printf("%lld\n",ans);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    scanf("%d %d",&c,&T);
    while(T--){
        solve();
    }
    return 0;
}
