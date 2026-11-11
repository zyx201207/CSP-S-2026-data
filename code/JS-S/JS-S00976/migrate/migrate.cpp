#include<bits/stdc++.h>
using namespace std;
#define ll long long
int c,t;
ll n,k;
ll a[2000001],sp[2000001];
void check(){

}
void solve(){
    int ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];sp[i]=0;
    }
    int ff=0;
    for(int i=1;(i+3)<=n;i++){
        if((a[i+3]-a[i])>k){
            if((a[i+2]-a[i])<=k){
                if((a[i+3]-a[i]+2)<=k){
                    if((a[i+1]-a[i])<=k){
                        if((a[i+3]-a[i+1])<=k){
                            sp[i]=1;
                            ff=1;
                        }
                    }
                }
            }
        }
    }
    if(ff==0){
        cout<<0<<endl;
    }
    else{
        cout<<1<<endl;
    }
}
ll dp[50001];
ll step[50001];
void solve2(){
    int ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int lst,stp;
    for(int i=1;i<=n;i++){
        lst=i;
        for(int j=(i+1);j<=n;j++){
            dp[j]=0;
            step[j]=0;
        }
        dp[i]=1;
        step[i]=0;
        for(int j=(i+1);j<=n;j++){
            while((a[j]-a[lst])>k){
                lst++;
            }
            stp=step[lst];step[j]=stp+1;
            for(int z=lst;z<j;z++){
                if(step[z]>stp){
                    break;
                }
                dp[j]+=dp[z];
            }
            if(dp[j]==2){
                ans++;
            }
            if(dp[j]==0){
                break;
            }
            //if(n<=10  && k==3){cout<<j<<" "<<dp[j]<<endl;

            //}

        }
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>t;
    while(t--){
        if(c<=10){
            solve2();
        }
        else{
            solve();
        }
    }
    return 0;
}
