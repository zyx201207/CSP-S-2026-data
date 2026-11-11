#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,q;
    cin>>c>>q;
    while(q--){
        int n;
        long long m,a[10005];
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        sort(a+1,a+1+n);
        int ans=0;
        for(int c1=1;c1<=n;c1++){
            for(int k1=c+1;k1<=n;k1++){
                int dp[10005]={0},dp2[10005]={0};
                dp[c1]=1;
                dp2[c1]=0;
                for(int i=c1+1;i<=k1;i++){
                    int j=i-1;
                    dp[i]=0;
                    dp2[i]=INT_MAX;
                    while(abs(a[i]-a[j])<=m&&j>=c1){
                        if(dp2[i]>(dp2[j]+1)){
                            dp2[i]=dp2[j]+1;
                            dp[i]=dp[j];
                        }
                        else if(dp2[i]==dp2[j]+1){
                            dp[i]+=dp[j];
                        }
                        j--;
                    }
                }
                if(dp[k1]==2){
                    ans++;
                }
            }
        }
        cout<<ans;
    }
    return 0;
}
