#include<bits/stdc++.h>
using namespace std;
int n,d,ans;
int a[2000005],dp[2000005];
int df(int x,int y,int l){
dp[x]=0;
for(int i=x;i<=y;i++){
int e=i-d;
    for(int j=1;j<=l;j++){
        if(a[j]>=e){
            e=j;
            break;
        }
    }
    for(int j=e;j<=i;j++){
        dp[i]+=dp[j]+1;
    }
    dp[i]=max(dp[i],dp[i-1]);
}
cout<<dp[y]<<" ";
return dp[y];
}
int main(){
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
//ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
int c,t;
cin>>c>>t;
while(t--){
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(df(a[j],a[i],j)==2)ans++;
            memset(dp,0,sizeof(dp));
        }
    }
    cout<<ans;
}
return 0;
}
