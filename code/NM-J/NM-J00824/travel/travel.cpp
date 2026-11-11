#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool f=1;
int main()
{freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
 //mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm
 cin>>s1>>c1>>s2>>c2;
  if(s1==s2)cout<<1;
   else {f=0;cout<<0;}
  if(f==1&&c1[0]==c2[0]&&c1[1]==c2[1])cout<<1;
   else {f=0;cout<<0;}
  if(f==1&&c1[2]<='C'&&c2[2]<='C'||c1[2]>='D'&&c2[2]>='D')cout<<1;
   else {cout<<0;f=0;}
  if(f==1&&abs(int(c1[2])-int(c2[2]))==1)cout<<1;
   else cout<<0;
    return 0;
}
