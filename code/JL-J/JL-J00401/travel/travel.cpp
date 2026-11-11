#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin>>c1>>c2>>c3>>c4;
    if(c1==c3){
        cout<<"1";
    }else{
        cout<<"0";
    }
   for(int i=0;i<=1;i++){
    if(c2[i]==c4[i]){
        cout<<"1";
     }else{
         cout<<"0";
     }
   }
    fclose(stdout);
    return 0;
}
