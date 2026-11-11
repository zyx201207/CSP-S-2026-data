#include<bits/stdc++.h>
using namespace std;
int r1,x1;
string r2,x2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
   cin>>r1>>r2>>x1>>x2;
   if(r1==x1)cout<<1;
   else{
    cout<<"0000";
    exit(0);
   }
   if(x2[0]+x2[1]==r2[0]+r2[1])cout<<1;
   else{
    cout<<"000";
    exit(0);
   }
   if(r2[2]=='A' or r2[2]=='B' or r2[2]=='C' and x2[2]=='A' or x2[2]=='B' or x2[2]=='C')cout<<1;
   else{
    if(r2[2]=='D' or r2[2]=='F' and r2[2]=='D' or r2[2]=='F')cout<<1;
    else{
        cout<<"00";
        exit(0);
    }
   }
   if(char(r2[2])==char(x2[2])+1 or char(r2[2])==char(x2[2])-1) cout<<1;
   else cout<<"0";
   fclose(stdin);
   fclose(stdout);
    return 0;
}
