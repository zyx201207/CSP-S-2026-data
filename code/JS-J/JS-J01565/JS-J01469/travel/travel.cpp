#include<bits/stdc++.h>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2)cout<<0<<0<<0<<0;
    else {cout<<1;
    for(int i=0;i<=1;i++){
        if(s1[i]!=s2[i]){
            cout<<0<<0<<0;
            return 0;
        }
    }
    cout<<1;
    //-----------------------------------
   if(s1[2]=='A'){
    if(s2[2]=='B')cout<<1<<1;
    else if(s2[2]=='C')cout<<1<<0;
    else cout<<0<<0;
   }
   else if(s1[2]=='B'){
    if(s2[2]=='A'||s2[2]=='C')cout<<1<<1;
    else cout<<0<<0;
   }
   else if(s1[2]=='C'){
    if(s2[2]=='B')cout<<1<<1;
    else if(s2[2]=='A')cout<<1<<0;
    else cout<<0<<0;
   }
   else if(s1[2]=='D'){
    if(s2[2]=='E')cout<<1<<1;
    else cout<<0<<0;
   }
   else if(s1[2]=='E'){
    if(s2[2]=='D')cout<<1<<1;
    else cout<<0<<0;
   }
    }
    return 0;
}
