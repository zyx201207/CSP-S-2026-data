#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   string c1,s1,c2,s2;
   cin>>c1>>s1>>c2>>s2;
   int a=0,b=0,c=0,d=0;
   if(c1==c2){
       a=1;
       if(s1[0]==s2[0] && s1[1]==s2[1]){
           b=1;
           int x=s1[2],y=s2[2];
           if(68<=x && x<=69 && 68<=y && y<=69){c=1;d=1;}
           else if(65<=x && x<=67 && 65<=y && y<=67){
               c=1;
               if(max(x,y)-min(x,y)==1) d=1;
           }
       }
   }
   cout<<a<<b<<c<<d;
   fclose(stdin);
   fclose(stdout);
   return 0;
}
