#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[2005],i,j,n,m,ans;
void dfs(ll x,ll sum,ll g){
    if(n-x+1<m-g){
         //   cout<<x<<' '<<sum<<' '<<g<<'\n';
        return;
    }
    if(g==m){
          //  cout<<x<<' '<<sum<<'\n';
        ans=max(ans,sum);
        return;
    }
    if(x==n+1){
      //  if(g<m){
            return;
       // }
     //   ans=max(ans,sum);
    }
    dfs(x+1,sum&a[x],g+1);
    dfs(x+1,sum,g);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    //freopen("and3.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n==m){
        ll ans=a[1];
        for(i=2;i<=n;i++){
            ans&=a[i];
            if(ans==0){
                break;
            }
        }
        cout<<ans<<'\n';
        return 0;
    }
    if(m==1){
        ll Max=0;
        for(i=1;i<=n;i++){
            Max=max(Max,a[i]);
        }
        cout<<Max<<'\n';
        return 0;
    }
    ll sum1=1,jis=2;
    for(i=1;i<=30;i++){
        sum1+=jis;
        jis*=2;
      // cout<<sum<<'\n';
    }
    ans=0;
    a[0]=sum1;
    dfs(1,sum1,0);
    cout<<ans<<'\n';
        //cout<<sum<<'\n';
  //  cout<<(sum&3)<<'\n';
    //for(i=1;i<=n;i++){
  //      for(j=1;j<=min(i,m);j++){
//            for(ll i1=0;i1<i;i1++){
        //        dp[i][j]=max(dp[i1][j],max(dp[i1][max(j-1,0ll)]&a[i],dp[i][j]));
      //      }
    //    }
  //  }
   // cout<<dp[n][m]<<'\n';
    return 0;
}
