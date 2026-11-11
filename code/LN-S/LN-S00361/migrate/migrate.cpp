#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAXN=5e3+7,INF=2e18+7,MOD=998244353;
int c,t;
int dp[MAXN][MAXN],cnt[MAXN][MAXN];
int far[MAXN];
int a[MAXN];
int n,d;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=INF;
                cnt[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int l=1,r=0;
        for(r=1;r<=n;r++){
            while(a[r]-a[l]>d){
                far[l]=r-1;
                l++;
            }
            far[l]=r;
            /*for(int i=l;i<=r;i++){
                for(int j=l;j<=r;j++){
                    if(i!=j){
                        dp[i][j]=1;
                        cnt[i][j]=1;
                    }
                    else{
                        dp[i][j]=0;
                        cnt[i][j]=1;
                    }
                }
            }*/
        }
        for(;l<r;l++){
            far[l]=r;
        }
        for(int len=2;len<=n;len++){
            for(int i=1;i+len-1<=n;i++){
                int j=i+len-1;
                if(j<=far[i]){
                    cnt[i][j]=1;
                    dp[i][j]=1;
                    continue;
                }
                for(int k=i+1;k<=far[i];k++){
                    if(1+dp[k][j]<dp[i][j]){
                        dp[i][j]=1+dp[k][j];
                        cnt[i][j]=cnt[k][j];
                    }
                    else if(1+dp[k][j]==dp[i][j]){
                        cnt[i][j]+=cnt[k][j];
                    }
                }
                if(cnt[i][j]==2){
                    ans++;
                }
            }
        }
        /*for(int i=1;i<=n;i++){
            cout<<far[i]<<" ";
        }
        cout<<endl;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                cout<<dp[i][j]<<" "<<cnt[i][j]<<"   ";
            }
            cout<<endl;
        }*/
        cout<<ans<<endl;
    }
    return 0;
}