#include<bits/stdc++.h>
using namespace std;
int n,x,cnt;
string s;
char z;
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  cin>>n;
  for(int i=1;i<=n;i++){
  	cin>>x>>z;
  	for(int j=1;j<=x;j++)s+=z;
  }
  for(int i=0;i<s.size();i++){
  	if(s[i]!=s[s.size()-1-i])cnt++;
  }
  cout<<(cnt+1)/2;
return 0;
}
