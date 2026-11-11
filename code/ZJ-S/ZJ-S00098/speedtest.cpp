#include<bits/stdc++.h>
using namespace std;
using u64=unsigned long long;

inline u64 shift(u64 x){
  x^=x<<13;
  x^=x>>7;
  x^=x<<17;
  return x;
}

int main(){
  u64 x=0;
  for(int i=1;i<=1000000000;++i){
    x+=shift(i);
  }
  cout<<x<<"\n";
  return 0;
}