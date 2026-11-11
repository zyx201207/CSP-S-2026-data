#include<bits/stdc++.h>
using namespace std;
int max1=-999999999;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.ans","w",stdout);
    long long n,m,o=0;
    cin>>n>>m;
    int a[n+10];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //for(int i=0;i<n;i++){
    //   for(int j=1;j<=n-i-1;j++){
     //       cout<<a[i]<<' '<<a[j]<<' '<<(a[i]|a[j])<<endl;
     //       max1=max(max1,a[i]|a[j]);
     //   }
    //}
   //cout<<max1;
   cout<<a[n-1];
    return 0;
}
