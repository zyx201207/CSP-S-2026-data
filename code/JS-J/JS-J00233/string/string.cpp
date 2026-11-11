#include<bits/stdc++.h>
using namespce std;
vector<char> s;
int main(){
  int n,x;
  char y;
  cin>>n;
  for(int i=1;i<=n;i++){
    cin>>x>>y;
    for(int j=1;j<=x;j++){
       s.push_back(y);
    }
  }
  int t=s.size(),ans=0;
  for(int i=1;i<=t/2;i++){
    if(s[i]!=s[t+1-i]) ans++;
  }
  cout<<ans;
  return 0;
}
