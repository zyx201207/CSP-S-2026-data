#include<bits/stdc++.h>
using namespace std;
string ax,ay,bx,by;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
   cin>>ax>>bx>>ay>>by;
   if(ax==bx){
      cout<<1;
   }
   else{
      cout<<"000";-
      return 0;
   }
      if(ax[1]==ay[1]&&bx[1]==bx[1])
      cout<<1;
       else{
               cout<<"000";
               return 0;
              }
    }
   if(ax[2]<='C'&&bx[2]<='C'){
         cout<<1;
   }
    else if(ax[2]>='D'&&bx[2]>='D'){
        cout<<"11";
        return 0;
   }
   else{
      cout<<"00";
      return 0;
   }
   fclose(stdin);
   fclose(stdout);
return 0;
}
