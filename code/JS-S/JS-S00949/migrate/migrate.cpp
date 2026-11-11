#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--){
    int n;
    ll d;
    cin>>n>>d;
    ll dp[200005]={ };
    int x[200005]={ };
    for(int i=1;i<=n;i++){
        cin>>x[i];
    }
    int dc[200005]={ };
    dc[1]=0;
    for(int i=2;i<=n;i++){
        dc[i]=x[i]-x[i-1];
    }
    dp[1]=0;
     for(int i=2;i<=n;i++){
            for(int j=2;j<i;j++){
        if(dc[i]==dc[j]){
            if(abs(x[i]-x[j])<=d){
                dp[i]++;
            }
        }
    }}
    ll ans=0;
    ll cnt=0;
     for(int i=1;i<=n;i++)
         for(int j=1;j<i;j++){
            if(dp[i]!=0&&dp[j]!=0&&abs(x[i]-x[j])<=d)
            dp[i]=dp[i]*dp[j];
            else{
                cnt++;
            }
     }

 for(int i=1;i<=n;i++){
    ans=max(dp[i],ans);
 }
 cout<<(ans+1)/2+cnt<<endl;
}
return 0;
}
