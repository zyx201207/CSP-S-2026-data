#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
 cin>>c1>>s1>>c2>>s2;
 int a1=10*(s1[0]-'0')+(s1[1]-'0');
 int a2=10*(s2[0]-'0')+(s2[1]-'0');
 if(c1==c2){
  printf("1");
  if(a1==a2){
   printf("1");
   if(s1[2]=='D'&&s2[2]=='F')printf("11");
   else if(s1[2]=='F'&&s2[2]=='D')printf("11");
   else if(s1[2]=='A'&&s2[2]=='B')printf("11");
   else if(s1[2]=='A'&&s2[2]=='C')printf("10");
   else if(s1[2]=='B'&&s2[2]=='C')printf("11");
   else if(s1[2]=='B'&&s2[2]=='A')printf("11");
   else if(s1[2]=='C'&&s2[2]=='A')printf("10");
   else printf("00");
  }
  else{ printf("000"); }
 }
 else{ printf("0000"); }
 freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
 return 0;
}
