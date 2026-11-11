#include<bits/stdc++.h>
#define int long long
using namespace std;
using i64=long long;
constexpr int N=5e5+10;

int n,ans;
i64 m,a[N],s[N];

signed main(){
  freopen("crystal.in","r",stdin);
  freopen("crystal.out","w",stdout);
  cin.tie(0)->sync_with_stdio(0);
  cin>>n>>m;
  for(int i=1;i<=n;++i)cin>>a[i];
  sort(a+1,a+n+1);
  for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
  auto check=[&](i64 val,int l,int r)->bool {
    return (r-l+1)*val-(s[r]-s[l-1])<=m;
  };
  for(int i=1;i<=n;++i){
    int l=0,r=i+1;
    while(l+1!=r){
      int mid=(l+r)>>1;
      if(check(a[i],mid,i))r=mid;
      else l=mid;
    }
    ans=max(ans,i-r+1);
  }
  cout<<ans<<endl;
  return 0;
}