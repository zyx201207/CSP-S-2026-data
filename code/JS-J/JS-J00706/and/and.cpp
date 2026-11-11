#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
   freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;

    long long a[n+1];
    for(int i=1;i<=n;i++)cin>>a[i];
   // cout<<"fin";
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
    }else{
      long long mans=a[n],lans=a[1],llans=a[1];
   // cout<<endl<<a[n]<<" ";
    for(int i=1;i<m;i++){
        mans=mans&a[n-i];
       lans=lans&a[1];
       llans=llans&a[i+1];
    //cout<<endl<<a[n-i]<<" ";
    }
     cout<<max(max(mans,lans),llans);
    }

    return 0;
}
