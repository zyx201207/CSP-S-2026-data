#include <bits/stdc++.h>

using namespace std;

int n,m;
int a[500005];

int tst(int x){
  int tmp = 0;
  for(int i = x-1;i>=1;i--){
    tmp+=a[x]-a[i];
    //    cout<<tmp<<endl;
    if(tmp>m)
      return x-i;
  }
  return x;
}

int main() {
  freopen("crystal.in", "r",stdin);
  freopen("crystal.out","w",stdout);
  cin>>n>>m;
  int t = 0;
  for(int i=1;i<=n;i++){
    cin>>a[i];
    t+=a[i];
  }
  sort(a+1,a+n+1);
  int mm = INT_MIN;
  for(int i=n;i>=1;i--){
    int ss = tst(i);
    //    cout<<ss<<endl;
    mm = max(mm, ss);
  }
  cout<<mm<<endl;
  return 0;
}
