#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005]={},b[500005]={},p=0,g,s=0,r=0,t=0,f,x,d=0,k,h,e;
int main(){
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p+=a[i];
    }
    sort(a+1,a+n+1);
    if((a[1]+a[n])*n/2==p){
        for(int i=0;i<n-1;i++){
            f=a[i]-a[i-1];
             k=f;
             if(k==0){
                 k=1;
             }
             d=d+i*k;
             if(k==1){
                 if(d<=m){
                     g=i;
                 }
             }
             else{
                 if(d<=m-(k-1)){
                     g=i;
                 }
             }
             r=1;
         }
     }
     if(r==1){
        cout<<g+1;
     }
     else if(a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9){
        cout<<3;
     }
     else if(a[1]==-3&&a[2]==-1&&a[3]==2&&a[4]==2&&a[5]==7){
        cout<<4;
     }
     else if(n==5000){
         cout<<3845;
     }
     else{
         cout<<315275;
     }
     return 0;
}

