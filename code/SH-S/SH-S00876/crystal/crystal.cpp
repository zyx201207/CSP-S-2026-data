#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,i,j,a[N],sum[N];
long long l,r,cs,ans;
int main(){
 freopen("crystal.in","r",stdin);
 freopen("crystal.out","w",stdout);
 cin>>n>>m;
 for(i=1;i<=n;i++)cin>>a[i];
 sort(a+1,a+n+1);
 for(i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
 l=1;r=1;
 ans=1;
 while(r<n){
  r++;
  if(a[r]!=a[r-1])cs=a[r]*(r-l)-(sum[r-1]-sum[l-1]);
  if(cs>m){
   while(l<r){
    cs=cs-(a[r]-a[l]);
    l++;
    if(cs<=m)break;
   }
  }else{
   ans=max(ans,r-l+1);
  }
 }
 ans=max(ans,r-l+1);
 cout<<ans;
 return 0;
} 
