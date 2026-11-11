#include<bits/stdc++.h>
using namespace std;
int n,m,a[510000],t=0;
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","W",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
       if(a[i]>=0&&m-a[i]>=0){
             m=m-(a[i+1]-a[i]);
             t++;
       }
       else if(a[i]<0&&m+a[i]>=0&&a[i+1]>=0){
          m=m-(a[i+1]-a[i]);
          t++;
       }
       else if(a[i]<0&&m+a[i]>=0&&a[i+1]<0){
          m=m+(a[i+1]+a[i]);
          t++;
       }
       else if(a[i]==a[i-1]){
          t++;
    }
    }
    cout<<t+1;
}
