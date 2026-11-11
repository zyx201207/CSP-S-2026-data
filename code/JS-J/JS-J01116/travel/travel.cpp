#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int k1,k2,k3,k4;
int main()
{
   freopen("travel.in","r",stdin);
   freopen("travel.out","w",stdout);
   getline(cin,s1);
   getline(cin,s2);
   getline(cin,s3);
   getline(cin,s4);
   if(s1!=s3)
   {
       cout<<"0000";
       return 0;
   }
   if((s2[0]!=s4[0])||(s2[1]!=s4[1]))
   {
       cout<<"1000";
       return 0;
   }
   if((s2[2]=='A'&&s4[2]=='D')||(s2[2]=='A'&&s4[2]=='E')||(s2[2]=='B'&&s4[2]=='D')||(s2[2]=='B'&&s4[2]=='E')||(s2[2]=='C'&&s4[2]=='D')||(s2[2]=='C'&&s4[2]=='E')||(s4[2]=='A'&&s2[2]=='D')||(s4[2]=='A'&&s2[2]=='E')||(s4[2]=='B'&&s2[2]=='D')||(s4[2]=='B'&&s2[2]=='E')||(s4[2]=='C'&&s2[2]=='D')||(s4[2]=='C'&&s2[2]=='E'))
   {
       cout<<"1100";
       return 0;
   }
   if((s2[2]=='A'&&s4[2]=='C')||(s2[2]=='C'&&s4[2]=='A'))
   {
       cout<<"1110";
       return 0;
   }
   cout<<"1111";
   return 0;
}
