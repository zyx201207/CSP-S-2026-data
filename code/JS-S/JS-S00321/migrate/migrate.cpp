#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
                 (__) 
                 (oo) 
           /------\/ 
          / |    ||   
         *  /\---/\ 
            ~~   ~~   
..."Have you mooed today?"...
*/

int x[2000010],dis[2000010];


signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        int n,d,ans=0;
        cin>>n>>d;
        cin>>x[1];
        for(int i=2;i<=n;i++)cin>>x[i],dis[i]=x[i]-x[i-1];
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j++){
                if(j-i<=1)continue;
                int islecnt=0;
                for(int k=i+1;k<=j-1;k++){
                    if(x[k]-x[i]<=d&&x[j]-x[k]<=d)islecnt++;
                }
                if(islecnt==2){ans++;}
            }
        }
        cout<<ans<<"\n";
    }
}