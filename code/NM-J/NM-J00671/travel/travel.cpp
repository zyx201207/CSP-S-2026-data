#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1,s1,c2,s2,n;
    cin>>c1>>s1>>c2>>s2;
      if(c1=c2)cout<<"1";
      else cout<<"0";
      else if(c1=s2+1||c1=s2-1)cout<<"1";
      else cout<<"0";
      else if(c2=c1+1||c2=c1-1)cout<<"1" ;
      else cout<<"0";
      else if(c2=s2)cout<<"1";
      else {
          cout<<"0";
          break;
       }
    return 0;
}

