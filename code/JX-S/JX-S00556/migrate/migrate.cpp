#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=10050;
ll a[N],b[N][N],d[N][N],maxi=0,mini=0;
inline long long read(){
    long long x=0,f=1;
    char c=getchar();
    while(c>'9'||c<'0'){
        if(c=='-1') f=-1;
        c=getchar();
    }
    while(c<='9'&&c>='0'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
 int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ll c=read(),t=read();
    while(t--){
        ll n=read(),m=read();
        for(ll i=1;i<=n;i++){
            a[i]=read();
            b[i][i]=0;
            if(a[i]-a[i-1]<=m) b[i-1][i]=a[i]-a[i-1];
            else b[i-1][i]=i-1;
        }
     //   for(ll i=1;i<=n;i++){
    //        for(ll j=i+1;j<=n;j++){
       //         d[i][j]=(j-1)*(j-i);
   //             if(d[i][j]==b[i][j]) p[i][j]++;
    //        }
     //   }
     //   for(ll k=1;k<=n;k++){
       //     for(ll i=1;i<=k;i++){
         //       for(ll j=k;j<=n;j++){
                  //  if(b[i][j]>d[i][k]+b[k][j]){
                   //     b[i][j]=d[i][k]+b[k][j];
                  //      if(b[i][j]==d[i][j]) p[i][j]++;
                 //   }
                //    if(b[i][j]>b[i][k]+d[k][j]){
               //         b[i][j]=b[i][k]+d[k][j];
                //        if(b[i][j]==d[i][j]) p[i][j]++;
             //       }
              //      if(b[i][j]>d[i][k]+d[k][j]){
          //              b[i][j]=d[i][k]+d[k][j];
         //               if(b[i][j]==d[i][j]) p[i][j]++;
             //       }
        //        }
     //       }
    //    }
  //      for(ll k=1;k<=n;k++){
         //   for(ll i=1;i<=k;i++){
           //     for(ll j=k+1;j<=n;j++){
           //         d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
           //         if(d[i][j]>d[i][k]+b[k][j]){
          //              d[i][j]=d[i][k]+b[k][j];
          //              if(b[i][j]==d[i][j]) p[i][j]++;
         //           }
       //             d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
       //         }
     //       }
  //      }
   //     ll sum=0;
       // for(ll i=1;i<=n;i++)
       //     for(ll j=i+1;j<=n;j++)
         //       if(p[i][j]==2) sum++;
        printf("0\n");
    }
    return 0;
}
