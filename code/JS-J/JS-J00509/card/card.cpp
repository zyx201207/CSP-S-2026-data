#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[50005];
int b[50005];
int c[50005];
int u=0;
int main(){
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   cin>>n>>m;
   for(int i=1;i<=n;i++){
       cin>>a[i];
   }
   for(int i=1;i<=n;i++){
        for(int q=i;q<=n;q++){
       u++;
       b[u]=a[i];
       for(int j=1;j<=i-1;j++){
           if(a[j]==a[i]){
              for(int w=1;w<=i-1;w++){
                  a[w]=-1;
              }
           }
       }
        }
        for(int e=1;e<=m;e++)
       for(int r=1;r<=u;r++)
           if(a[r]==e){c[e]++;break;}
   }
   for(int i=1;i<=m;i++){
       cout<<c[i]<<' ';
   }
    return 0;
}
