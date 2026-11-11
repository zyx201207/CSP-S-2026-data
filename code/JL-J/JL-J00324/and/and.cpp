#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
   int n,m;
   cin>>n>>m;int maxl=1,s=0;
   for(int i=1;i<=n;i++) cin>>a[i];
   for(int i=1;i<=n;i++){

    for(int j=1;j<=m;j++){
        s=a[i]&=a[i+1];
    }
    if(s>maxl) maxl=s;
   }
   cout<<maxl;
   return 0;
}
