#include <bits/stdc++.h>
using namespace std;
string n1,n2,w1,w2;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   ios::sync_with_stdio(false);
   cin.tie(0);
   cin>>n1>>w1>>n2>>w2;
   if(n1==n2)cout<<1;
   else cout<<0;
   if(n1==n2&&w1[0]==w2[0]&&w1[1]==w2[1])cout<<1;
   else cout<<0;
   if(n1==n2&&w1[0]==w2[0]&&w1[1]==w2[1]){
   if(w1[2]<='C'&&w2[2]<='C')cout<<1;
   else if(w1[2]>='D'&&w1[2]>='D')cout<<1;
   else cout<<0;
   }
   else cout<<0;
   if(n1==n2&&w1[0]==w2[0]&&w1[1]==w2[1]){
   if(w1[2]<='C'&&w2[2]<='C'){
   if(abs(w1[2]-w2[2])==1)cout<<1;
   else cout<<0;   
   }
   else if(w1[2]>='D'&&w1[2]>='D'){
   if(abs(w1[2]-w2[2])==1)cout<<1;
   else cout<<0;
   }
   else cout<<0;
   }
   else cout<<0;
   return 0;
}
