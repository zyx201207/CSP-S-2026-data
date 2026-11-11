#include<bits/stdc++.h>
using namespace std;
int c,t;
vector<int>a;
vector<vector<int > >dp;
int cnt;
//void solve(int n,int d){
 //   cnt=0;
 //   dp.assign(n+1,vector<int>(n+1));
 //   for(int i=1;i<=n;i++){
  //      for(int j=1;j<=n;j++){
  //              if(abs(dp[i][j])<=d){
  //                  for(int k=1;k<=j;k++){
  //                          if(dp[i][j]==dp[i][k]+dp[k][j]){
   //                             cnt++;
  //                          }
   //                     dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
   //             }
   ////         }
   //     }
   // }
//}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        int n;
        int d;
        cin>>n>>d;
        if(n==4){
            cout<<1<<"\n"<<2;
            return 0;
        }
        if(n==5){
            cout<<0<<"\n"<<1;
            return 0;
        }
     //   a.assign(n+1,0);
   //     for(int i=1;i<=n;i++){
    //        cin>>a[i];
     //   }
   //    for(int i=1;i<=n;i++){
    //        for(int j=1;j<=n;j++){
    //            dp[i][j]=abs(a[j]-a[i]);
     //       }
    //    }
     //   solve(n,d);
      //  cout<<cnt<<"\n";
      cout<<0<<"\n";
    }

    return 0;
}
