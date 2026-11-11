#include<bits/stdc++.h>
using namespace std;
long long d,dp[2000005],a[2000005],s[2000005],min_=0x3f3f3f3f;
int c,t,n,ans=0;
int f(int x){
    dp[x]=1;
    s[x]=0;
    for(int i=x+1;i<=n;i++){
        dp[i]=0;
        min_=0x3f3f3f3f;
        for(int j=i-1;a[i]-a[j]<=d && j>=x;j--){
            min_=min(min_,s[j]);
        }
        s[i]=min_;
        for(int j=i-1;a[i]-a[j]<=d && j>=x;j--){
            if(s[j]==s[i]) dp[i]+=dp[j];
        }
        s[i]+=1;
    }
    for(int i=x+1;i<=n;i++){
        if(dp[i]==2){
            ans++;
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++) f(i);
        cout<<ans<<endl;
    }
    return 0;
}

