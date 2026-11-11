#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string a,b,c,d,e;
   cin>>a>>b>>c>>d;
   if(a[0]-'0'==c[0]-'0'&&a[1]-'0'==c[1]-'0'){
     cout<<1;
   }else{
      cout<<0;
      cout<<0;
      cout<<0;
      cout<<0;
      return 0;
   }
   if(b[0]-'0'==d[0]-'0'&&b[1]-'0'==d[1]-'0'){
      cout<<1;
   }
   else{
      cout<<0;
      cout<<0;
      cout<<0;
      return 0;
   }
  int x=b[2]-'A';
  int y=d[2]-'A';
  int z=abs(x-y);
  if(x<3&&y<3){
    cout<<1;
  }
  else if(x>2&&y>2){
    cout<<1;
  }
  else{
    cout<<0;
    cout<<0;
    return 0;
  }
  if(z==1){
    cout<<1;
  }else{
     cout<<0;
  }
   return 0;
}
