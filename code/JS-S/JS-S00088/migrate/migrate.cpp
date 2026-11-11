#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10;
int n,d,a[N];
int r[N],dp[N],f[N],fdp[N];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C,T;
    cin>>C>>T;
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1,j=1;i<=n;i++){
            while(j<n&&a[j+1]-a[i]<=d) j++;
            r[i]=j;
        }
        int ans=0;
        for(int i=n;i>=1;i--){
            if(r[i]==i) f[i]=0;
            else{
                if(r[i]-max(i,r[i-1])>=1){
                    f[i]=r[i]-max(i,r[i-1])+f[r[i]];
                }
                else f[i]=0;
            }
        }
        for(int i=n;i>=1;i--){
            if(r[i]==r[i-1]||r[i]==i) fdp[i]=0;
            else if(r[i]==r[i-1]+1||r[i]==i+1) fdp[i]=fdp[r[i]];
            else{
                fdp[i]=r[r[i]-1]-r[r[i]-2];
                if(r[r[i]]>r[r[i]-1]){
                    if(r[r[i]]>r[r[i]-1]+1) fdp[i]+=dp[r[i]];
                    else dp[i]+=dp[r[r[i]]];
                }
                else if(r[r[i]-1]>r[r[i]-2]) dp[i]+=f[r[r[i]]];
            }
        }
        int tmp=0;
        for(int i=n;i>=1;i--){
            if(r[i]==i) dp[i]=0;
            else if(r[i]==i+1) dp[i]=dp[i+1];
            else{
                dp[i]=r[r[i]-1]-r[r[i]-2];
                if(r[r[i]]>r[r[i]-1]){
                    if(r[r[i]]>r[r[i]-1]+1) dp[i]+=dp[r[i]];
                    else dp[i]+=fdp[r[r[i]]];
                }
                else if(r[r[i]-1]>r[r[i]-2]) dp[i]+=f[r[r[i]]];
            }
            if(r[i]==r[i-1]||r[i]==i) fdp[i]=0;
            else if(r[i]==r[i-1]+1||r[i]==i+1) fdp[i]=fdp[r[i]];
            else fdp[i]=dp[i];
            ans+=dp[i];
        }
        cout<<ans<<'\n';
    }
    return 0;
}
