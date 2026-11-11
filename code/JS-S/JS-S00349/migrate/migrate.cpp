//24
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=3e6+5,M=4e3+5;
int c,t,n,d,arr[N];
int dp[M][M];
unordered_map<int,int>cn;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>arr[i];
        fill(&dp[0][0],&dp[n+1][n+1],1e18);
        for(int i=1;i<=n;i++){
            dp[i][i]=0;
            for(int j=i;j<=n;j++){
                cn.clear();
                for(int k=i;k<=j;k++){
                    if(abs(arr[j]-arr[k])<=d){
                        cn[dp[i][k]+1]++;
                        dp[i][j]=min(dp[i][j],dp[i][k]+1);
                    }
                }
                if(cn[dp[i][j]]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
