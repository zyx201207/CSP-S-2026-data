#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
unsigned int n,d;
unsigned int x[1005];
int dp[1005][1005];
int p[1005][1005];
int ans;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int y;
        for(int i=1;i<=n;i++){
            cin>>y;
            x[i]=y+1000000000000000000;
        }
        ans=0;
        memset(dp,0,sizeof(dp));
        memset(p,0,sizeof(p));
        for(int len=2;len<=n;len++){
            for(int l=1,r=len;r<=n;l++,r++){
                dp[l][r]=123456789;
                if(x[r]-x[l]<=d){
                    dp[l][r]=1;
                    p[l][r]=1;
                }
                else{
                    for(int k=l+1;k<=r-1;k++){
                        if(dp[l][r]>dp[l][k]+dp[k][r]){
                            dp[l][r]=dp[l][k]+dp[k][r];
                            p[l][r]=p[l][k]*p[k][r];
                        }
                        else if(dp[l][r]==dp[l][k]+dp[k][r]){
                            p[l][r]+=p[l][k]*p[k][r];
                        }
                    }
                }
            //    cout<<l<<' '<<r<<' '<<dp[l][r]<<' '<<p[l][r]<<'\n';
                ans+=(p[l][r]==2);
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}
/*
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
//g++ migrate.cpp -o migrate -std=c++11
/*
Where there's a will there's a way kind of beautiful
And evert night has its day so magical
And if there's love in this life there's no obestable
That can't be defeated
Monday left me broken
Tuesday I was through with hoping
Wednesday my empty arms were open
Thursday waiting for love waiting for love
Thanks the stars it's Friday
I'm burning like fire gone wild on Saturday
Guess I won't be coming to church on Sunday
I've been waiting for love waiting for love
*/