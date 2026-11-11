#include<bits/stdc++.h>
using namespace std;
long long c1,c2;
vector<int>s1;
vector<int>s2;
int main(){
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   cin>>c1;
   for(int i = 1;i < 3;i++){
       cin>>s1[i];
   }
   cin>>c2;
   for(int i = 1;i < 3;i++){
       cin>>s2[i];
   }
   if(c1 == c2){
     cout<<"1";
   }
   else{
   cout<<"0";
   }
   if(s1[0] == s2[0]&&s1[1] == s2[1]){
      cout<<"1";
    }
    else{
        cout<<"0";
    }
    if(s1[0] == s2[0]&&s1[1] == s2[1]&&s1[2] == s2[2]){
       cout<<"1";
       }
    else{
         cout<<"0";
         }
    if(s1[2]==s2[2]+1||s1[2] == s2[2]-1){
       cout<<"1";
       }
    else{
       cout<<"0";}
fclose;
return 0;
}
