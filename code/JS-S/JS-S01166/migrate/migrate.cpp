#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[2000006],d[2000006],dp[5006][5005],cnt[5005][5005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    scanf("%lld%lld",&c,&t);
    while(t--){
        ll n,m,sum=0;
        scanf("%lld%lld",&n,&m);
        for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
        //for(lli=1;i<=n;i++)cout<<b[i]<<" ";
        //cout<<endl;
        d[n]=n;
        for(ll i=n-1,r=n;i>0;i--){
            while(m<a[r]-a[i])r--;
            d[i]=r;
        }
        memset(dp,0x3f,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        for(ll i=1;i<=n;i++){
            dp[i][i]=0;
            cnt[i][i]=1;
        }
        for(ll i=1;i<=n;i++){
            for(ll j=i+1;j<=d[i];j++){
                dp[i][j]=1;
                cnt[i][j]=1;
            }
        }
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                for(ll k=i+1;k<j;k++){
                    if(dp[i][k]!=0x3f3f3f3f && dp[k][j]!=0x3f3f3f3f){
                        if(dp[i][j]>dp[i][k]+dp[k][j]){
                            dp[i][j]=dp[i][k]+dp[k][j];
                            cnt[i][j]=cnt[i][k]*cnt[k][j];
                        }
                        else if(dp[i][j]==dp[i][k]+dp[k][j])cnt[i][j]+=cnt[i][k]*cnt[k][j];
                    }
                }
/*
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++)cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++)cout<<cnt[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;*/
            }
        }
        for(ll i=1;i<n;i++){
            for(ll j=i+1;j<=n;j++){
                if(dp[i][j]!=0x3f3f3f3f && cnt[i][j]==2)sum++;
            }
        }
        printf("%lld\n",sum);
    }
    return 0;
}
