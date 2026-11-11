#include <bits/stdc++.h>

using namespace std;

int main(){
  freopen("migrate.in","r",stdin);
  freopen("migrate.out","w",stdout);
  int c,t;
  int x[2000005];
  cin>>c>>t;
  for(int i=1;i<=t;i++){
    int n,d;
    cin>>n>>d;
    for(int j=1;j<=n;j++){
      cin>>x[j];
    }
    cout<<( n-d-(x[1]<0?x[n-1]:1)<0?n-1:(n-d-(x[1]<0?x[n-1]:1)) )<<endl;
  }

  return 0;
}
