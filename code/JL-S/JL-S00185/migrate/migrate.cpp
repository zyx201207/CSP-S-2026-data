#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5005;
int c,T,dp[N],n,d,a[N];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int ans=0;
        for(int k=1;k<=n;k++){
            dp[k]=0;
            int sum=1e9,res=1e9,flag=0;
            for(int l=k,r=k+1;r<=n;r++){
                while(a[r]-a[l]>d){
                    l++;
                }
                dp[r]=dp[l]+1;
                if(l==r)break;
                if(dp[r]==dp[r-1])flag++;
                else if(dp[r]>dp[r-1] && flag==1){
                    ans++;
                }
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
