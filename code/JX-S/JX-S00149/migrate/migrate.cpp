#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c,t;
    cin>>c>>t;
    for(ll k=0;k<t;k++){
        ll cnt=0;
        ll n,d;
        cin>>n>>d;
        ll a[n+1]={0};
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        ll z=a[2]-a[1];
        for(ll i=1;i<=n;i++){
            a[i]/=z;
        }
        for(ll i=1;i<=n;i++){
            ll dp[n+1-i]={0};
            dp[0]=0;
            dp[1]=0;
            ll dp1[n+1-i]={0};
            for(ll j=2;j<=n+1-i;j++){
                dp[j]=dp[j-1]+1;
                ll ab=1;
                for(ll f=2;f<=d;f++){

                    if(j-f>=1){
                        if(dp[j]==dp[j-f]+1){
                            ab++;
                        }else if(dp[j]>dp[j-f]+1){
                            dp[j]=dp[j-f]+1;
                            ab=1;
                        }
                    }
                }
                dp1[j]=ab;

            }
            for(ll j=i+1;j<=n+1-i;j++){
                if(dp1[j]==2){
                    cnt++;
                }
            }
            /*for(int j=1;j<=n+1-i;j++){
                cout<<dp[j]<<" ";
            }
            cout<<endl;*/
        }
        cout<<cnt<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
