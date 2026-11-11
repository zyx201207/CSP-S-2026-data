#include<iostream>
#include<algorithm>
using ll=long long;
const int sz=5e5+10;
ll a[sz],sum[sz];
int main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  int n;
  ll m;
  std::cin>>n>>m;
  for(int i=1;i<=n;i++)std::cin>>a[i];
  std::sort(a+1,a+n+1);
  for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
  int ans=0;
  for(int l=1,r=1;l<=n;l=r){
    while(a[r]==a[l])r++;
    int bl=1,br=l;
    while(bl<br){
      int mid=bl+br>>1;
      if((l-mid)*a[l]-sum[l-1]+sum[mid-1]<=m)br=mid;
      else bl=mid+1;
    }
    ans=std::max(ans,r-bl);
  }
  std::cout<<ans<<"\n";
  return 0;
}