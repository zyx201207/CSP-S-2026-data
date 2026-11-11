#include<bits/stdc++.h>
using namespace std;
long long a[1000000000005];
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
long long n,m,s=0,p;
cin>>n>>m;
cin>>a[n];
if(a[n]%2==0){ 
p==a[n]/2;
 }
  else{
  p==a[n-1]/2;
  }
  for(int i=1;i<=m;i++){
  a[n]++;
  if(p==a[n])
  s++;
  }
cout<<s;
   return 0;
}