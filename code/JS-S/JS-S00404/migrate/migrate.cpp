#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
long long c,t,n,d,a[N],dp[N][2];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            long long va=a[2]-a[1];
            long long each=d/va;
            if(each==0||each==1){
                cout<<0<<'\n';
                continue;
            }
            long long ans=0;
            for(int i=1;i<n;i++){
                if(n-i>each*2-2)ans++;
            }
            cout<<ans<<'\n';
        }
        return 0;
    }
    if(c==13||c==14){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            if(a[n]-a[1]<=d)cout<<0<<'\n';
            else if(a[n]-a[1]==d*2)cout<<2<<'\n';
            else if(a[n]-a[1]==d*2-1)cout<<1<<'\n';
            else cout<<0<<'\n';
        }
        return 0;
    }
    while(t--){
        long long ans=0;

        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                dp[j][0]=1e18,dp[j][1]=0;
            }
            int l=i;
            dp[i][0]=0,dp[i][1]=1;
            for(int j=i+1;j<=n;j++){
                while(l<=j&&a[j]-a[l]>d)l++;
                if(l>j)continue;
                for(int k=l;k<j;k++){
                    if(dp[k][0]+1<dp[j][0])dp[j][0]=dp[k][0]+1,dp[j][1]=dp[k][1];
                    else if(dp[k][0]+1==dp[j][0])dp[j][1]+=dp[k][1];
                }
            }
            for(int j=i+1;j<=n;j++){
                if(dp[j][0]!=1e18&&dp[j][1]==2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
