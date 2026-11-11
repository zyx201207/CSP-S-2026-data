#include <bits/stdc++.h>
using namespace std;
char a[200005];
long long s[200005];
string k,m;
int main(){
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);

  int n;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s[i]>>a[i];
}
  long long sum=0;
  long long p=0;
  long long v=0;

  for(int i=0;i<n;i++){
    for(int j=0;j<s[i];j++){
        k[sum]=a[i];
        sum++;
    }
  }

  long long f=0;
  for(int i=0;i<n;i++){
    f+=s[i];
  }

  for(int i=0;i<f;i++){
    m[i]=k[f-1-i];
  }
  for(int i=0;i<f;i++){
    if(k[i]!=m[i]){
        v++;
    }
  }
  cout<<v/2;
  return 0;
}
