#include<bits/stdc++.h>
using namespace std;
int n;
int a[100000001];
long long m;
int main(){
   freopen("crystal.in","r",stdin);
   freopen("crystal.out","w",stdout);

   cin>>n>>m;
   for(int i=1;i<=n;i++){
    cin>>a[i];
   }
   if(m==1) {cout<<2;}
   else if(m%n==0) {cout<<n;}
   else{for(int i=1;i<n;i++){
        if((m+i)%n==0) {cout<<n-i;return 0;}
   }}
   return 0;
}
