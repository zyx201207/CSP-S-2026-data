#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
int a[N];
int ans;
void dfs(int n,int d,int now,int st,int mx) {
  if(now>=n) {
    if(st==mx) ans++;
    return;
  }
  for(int i=1;i<=d && now+i<=n;i++) {
    if(i%(a[2]-a[1])==0)
      dfs(n,d,now+i,st+1,mx);
  }
}
int main() {
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  int c,t;
  cin>>c>>t;
  while(t--) {
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n;i++) {
      cin>>a[i];
    }
    int mx=(a[n]-a[1]-1)/(d)+1;
    int gc=a[2]-a[1];
    if(a[2]-a[1]>d) {
      cout<<"0\n";
      continue;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
      for(int j=i+1;j<=n;j++) { //i->j
        ans=0;
        dfs(j,d,i,0,mx);
        if(ans==2) {
          cnt++;
        }
      }
    }
    cout<<cnt<<'\n';
  }
  return 0;
}
