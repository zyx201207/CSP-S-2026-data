#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
ll n,d;
ll a[2000010];
int dp[5005][5005];
int f[5005][5005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(ll i=1;i<=n;i++){
            cin>>a[i];
        }
        if(c<=6){
            memset(f,127,sizeof f);
            memset(dp,0,sizeof dp);
            for(int i=1;i<=n;i++)f[i][i]=0;
            for(int i=1;i<=n;i++){
                for(int p=i;p<n;p++){
                    if(a[p+1]-a[p]>d)break;
                    for(int q=p+1;a[q]-a[p]<=d&&q<=n;q++){
                        if(f[i][q]>f[i][p]+1){
                            dp[i][q]=1;
                            f[i][q]=f[i][p]+1;
                        }else if(f[i][q]==f[i][p]+1){
                            dp[i][q]++;
                        }
                    }
                }
            }
            int cnt=0;
            for(int i=1;i<n;i++){
                for(int j=i+1;j<=n;j++){
                    if(dp[i][j]==2){
                        cnt++;
                    }
                }
            }
            cout<<cnt<<'\n';
        }

    }
    return 0;
}


