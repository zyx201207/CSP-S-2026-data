#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool bh(char a){
    if(a=='A'||a=='B'||a=='C')return 0;
    else return 1;
}
int main(){
      freopen("travel.in","r",stdin);
      freopen("travel.out","w",stdout);
      cin>>c1>>s1>>c2>>s2;
      if(c1!=c2){
          cout<<"0000"<<endl;
      }else if(s1[0]!=s2[0] || s1[1]!=s2[1]){
          cout<<"1000"<<endl;
      }else if(bh(s1[2])!=bh(s2[2])){
          cout<<"1100"<<endl;
      }else if((s1[2]=='A'||s2[2]=='A')&&abs(s1[2]-s2[2])==2){
          cout<<"1110"<<endl;
      }else{
          cout<<"1111"<<endl;
      }
      return 0;
}
