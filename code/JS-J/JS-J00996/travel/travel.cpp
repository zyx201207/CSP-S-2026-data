#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
long long z,y;
bool q,w;
bool p[10005];
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   cin>>a>>b>>c>>d;
   if(a==c){
        p[1]=1;
   }
   else{
        cout<<"0000";
        return 0;
   }
   z=(b[0]-'0')*10+(b[1]-'0');
   y=(d[0]-'0')*10+(d[1]-'0');
   if(z==y){
        p[2]=1;
   }
   else{
        cout<<p[1]<<"000";
        return 0;
   }
   if(b[2]=='D' || b[2]=='F'){
        q=1;
   }
   if(d[2]=='D' || d[2]=='F'){
        w=1;
   }
   if(q==w){
        p[3]=1;
   }
   else{
        cout<<p[1]<<p[2]<<"00";
        return 0;
   }
   if(q==1 && w==1){
     cout<<"1111";
   }
   else if(b[2]=='B' || d[2]=='B'){
     cout<<"1111";
   }
   else{
     cout<<"1110";
   }
    return 0;
}
