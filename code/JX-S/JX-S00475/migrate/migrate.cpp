#include<bits/stdc++.h>
using namespace std;
int T,c;
const int MAXN=5e5+5;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    while(T--){
        long long n,d,a[MAXN]={},ans=0,dp[MAXN]={};
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=n-1;i>=0;i--){
            int l=i,r=n;
            while(l<=r){
                long long mid=(l+r)>>1;

                if((a[mid]-a[i])<=d){
                    l=mid+1;
                    dp[i]=max(dp[i],mid);
                }else{
                    r=mid-1;
                }
            }
            dp[i]=min(dp[i],n);
        }
        for(int i=1;i<n;i++){
            if(dp[i]!=i&&(dp[dp[i]]-dp[i-1])>0){
                ans+=dp[i]-dp[i-1];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
