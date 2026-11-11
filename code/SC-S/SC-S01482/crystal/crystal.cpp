//by SC-S01482 luogu 553188 on Linux
#include <bits/stdc++.h>
using ll=long long;
using namespace std;
const int N=5e5+3;
inline ll read() {
  ll x=0; char c=getchar();
  bool f=0;
  while(!isdigit(c)) f|=(c=='-'),c=getchar();
  while(isdigit(c)) {
    x=(x<<1)+(x<<3)+(c&15);
    c=getchar();
  }
  return f?-x:x;
}
ll a[N],m;
int n;
ll sum[N];
int check(ll tar,int id) { // a[i]==mid
  //tar*(id-i+1)-(a[i]+...+a[id])<=m, sum[id]-sum[i-1]>m
  //sum[i-1]<sum[id]-m last(max) i
  int l=1,r=id,best=-1; //best=min i-1
  while(l<=r) {
    int mid=(l+r)>>1;
    //min i let
    if(sum[mid]<=m-tar*(id-mid)+sum[id]) r=mid-1,best=mid;
    else l=mid+1;
  }
  if(best==-1) return 0;
  best++;
  return id-best+1;
}
int check2(ll tar,int id) {
  ll cnt=0;
  ll use=0;
  for(int i=id;i>=1;i--) {
    ll c=tar-a[i];
    if(use+c<=m) use+=c,cnt++;
    else break; //find max i
  }
  return cnt;
}
int main() {
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  n=read();
  m=read();
  for(int i=1;i<=n;i++) {
    a[i]=read();
  }
  sort(a+1,a+1+n);
  for(int i=1;i<=n;i++) {
    sum[i]=sum[i-1]+a[i];
  }
  int ans=0;
  if(n<=5000) {
      for(int i=1;i<=n;i++) {
        ans=max(ans,check2(a[i],i));
      }
  } else {
      for(int i=1;i<=n;i++) {
        ans=max(ans,check(a[i],i));
      }
  }
  cout<<ans;
  return 0;
}
