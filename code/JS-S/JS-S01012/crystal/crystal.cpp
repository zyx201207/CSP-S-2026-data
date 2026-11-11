#include<bits/stdc++.h>
#define rep(i, a, b) for (int i=(a),i##_E_=(b);i<=i##_E_;++i)
#define drep(i, a, b) for (int i=(a),i##_E_=(b);i>=i##_E_;--i)
using namespace std;
using ll = long long;

void ofile(string s){
  freopen((s+".in").c_str(),"r",stdin);
  freopen((s+".out").c_str(),"w",stdout);
}

int n;
ll m,a[500010],sum[500010];

int main(){
  ofile("crystal");
  scanf("%d%lld",&n,&m);
  rep(i,1,n)scanf("%lld",&a[i]);
  sort(a+1,a+n+1);
  rep(i,1,n)sum[i]=sum[i-1]+a[i];
  int j=1,ans=0;
  rep(i,1,n){
    while (sum[i]-sum[j-1]+m<a[i]*(i-j+1))++j;
    ans=max(ans,i-j+1);
  }
  printf("%d\n",ans);
  return 0;
}