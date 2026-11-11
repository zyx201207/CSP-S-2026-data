#include<bits/stdc++.h>
using namespace std;

int main()
{

 freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);

 string c1,s1,c2,s2;
 int flag=0;
 int flag1=0;
 cin>>c1>>s1>>c2>>s2;
 if(c1==c2)
 {
     cout<<"1";
     flag=1;
 }
 else
 {
    cout<<"0";
 }
 if(flag==1)
 {
    if(s1[0]==s2[0]&&s1[1]==s2[1])
    {
     cout<<"1";
     flag1=1;
    }
    else
    {
     cout<<"0";
    }
 }
 else
 {
     cout<<"0";
 }
 int flagr=0,flagx=0;
 int flag2=0;
 if(flag1==1)
 {
    if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
    {
     flagr=1;
    }
    if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')
    {
     flagx=1;
    }
    if(s1[2]=='D'||s1[2]=='F')
    {
     flagr=2;
    }
    if(s2[2]=='D'||s2[2]=='F')
    {
     flagx=2;
    }
    if(flagr==flagx)
    {
        cout<<"1";
        flag2=1;
    }
    else
    {
        cout<<"0";
    }
 }
 else
 {
   cout<<"0";
 }
 if(flag2==1)
 {
   if(s1[2]=='D'||s1[2]=='F'||s1[2]=='B'||s2[2]=='B')
   {
       cout<<"1";
   }
   else
   {
       cout<<"0";
   }
 }
 else
 {
   cout<<"0";
 }
 return 0;
}
