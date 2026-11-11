#include<bits/stdc++.h>
using namespace std;
int main(){
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  string a,b,c,d;
  cin>>a>>b>>c>>d;
  string str={};
  if(a==c) str+='1';
  if(a!=c){
    cout<<"0000";
    return 0;
  }
  int q,w;
  q=(b[0]-'0')*10+(b[1]-'0');
  w=(d[0]-'0')*10+(d[1]-'0');
  if(q==w) str+='1';
  if(q!=w){
    cout<<"1000";
    return 0;
  }
  bool f=((b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]=='A' || d[2]=='B' || d[2]=='C')) || ((b[2]=='D'||b[2]=='E') && (d[2]=='D' || d[2]=='E'));
  if(f) str+='1';
  if(f==0){
    cout<<"1100";
    return 0;
  }
  int e,r;
  e=b[2]-'A'+1;
  r=d[2]-'A'+1;
  bool m=(e==3 && r==4) || (e==4 && r==3);
  if(abs(e-r)==1 && m==0) str+='1';
  if(abs(e-r)!=1 || m==1) str+='0';

  cout<<str;
  return 0;
}
