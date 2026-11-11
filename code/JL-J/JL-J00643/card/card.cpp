#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
    int n,m,f;
    string s="";
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];



   // for(int i=1;i<=n;i++){
    //    f=i;
     //   for(int j=i;j<=n;j++){
      //      if(a[j]==a[f]){
     //           f=j;
      //      }
      //  }
     //   if(f==1)
   // }

    for(int i=1;i<=m;i++) cout<<a[m];


    return 0;
}
