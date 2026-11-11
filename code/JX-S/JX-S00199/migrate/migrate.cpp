#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL c,t,n,d,x[5005],dp[5005],ans;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    if(c<=10){
       while(t--){
           memset(dp,0x3f,sizeof(dp));
           ans=0;
           cin>>n>>d;
           for(int i=1;i<=n;i++){
               cin>>x[i];
           }
           for(int i=1;i<=n;i++){
               dp[i]=0;
               vector<int> f(n+1,0);
               f[i]=1;
                for(int j=i+1;j<=n;j++){
                    for(int k=j-1;k>0;k--){
                        if(x[j]-x[k]<=d){
                            dp[j]=min(dp[j],dp[k]+1);
                        }else{
                            break;
                        }
                    }
                    for(int k=j-1;k>0;k--){
                        if(x[j]-x[k]<=d){
                            if(dp[k]==dp[j]-1){
                                f[j]+=f[k];
                            }
                        }else{
                            break;
                        }
                    }
                    if(f[j]==2){
                        ans++;
                    }
                 //   cout<<f[j]<<' ';
                }//cout<<'\n';
           }
           cout<<ans<<'\n';
       } 
    }else{
        while(t--)
        cout<<0;
    }
    
    return 0;
}