#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
  int n,m;
  cin>>m>>n;
  for(int i=1;i<=m;i++){
    cin>>a[i];
  }
  int ans=a[1]&a[2];
  for(int i=3;i<=n;i++){
    ans=ans&a[i];
  }
  cout<<ans;
  return 0;
}
