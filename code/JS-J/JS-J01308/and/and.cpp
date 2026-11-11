#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
   int n,m;
   int a[50005][32],b[50005],c[50005],d[50005];
   cin>>n>>m;
   if(n>50000) return 0;
   for(int i=1;i<=n;i++){
       b[i]=1;
   }
   for(int i=1;i<=n;i++){
       cin>>d[i];
       c[i]=d[i];
   }


   for(int i=1;i<=n;i++){
       for(int j=32;j>=1;j--){
           a[i][j]=c[i]%2;
           c[i]/=2;
       }
   }
   for(int j=1;j<=32;j++){
       int s=0;
       for(int i=1;i<=n;i++){
           if(a[i][j]==1 && b[i]==1) s++;
       }
       if(s>=m){
           for(int i=1;i<=n;i++){
               if(a[i][j]==0) b[i]=0;
           }
       }
   }

   int x=INT_MAX;
   for(int i=1;i<=n;i++){
       if(b[i]==1) x=x&d[i];
   }
   cout<<x;
   fclose(stdin);
   fclose(stdout);
   return 0;
}

