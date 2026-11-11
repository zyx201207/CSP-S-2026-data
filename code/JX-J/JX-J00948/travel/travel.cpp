#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
 string c1,c2,c3,c4;
 int i1,i2,i3,i4,a,b;
 freopen("travel.in","r",stdin);
 freopen("travel.out","w",stdout);
 cin>>c1>>c2>>c3>>c4;
 if(c1[0] == c3[0] && c1[1] == c3[1])
 {
     i1=1;
 }
 else{
    i1=0;
 }
 if(c2[1] == c4[1]) i2 = 1;
 else{
    i2=0;
 }
 if(c2[2]){
     if(c2[1] == c4[1]) i3 = 1;
 else{
    i3 = 0;
  }
 }
 if (c2[2] == 'C' && c4[2] == 'D')
   i4 = 0;
 else{
  if(c2[2] == 'F') a=1;
  if(c2[2] == 'D') a=2;
  if(c2[2] == 'C') a=3;
  if(c2[2] == 'B') a=4;
  if(c2[2] == 'A') a=5;
  if(c4[2] == 'F') b=1;
  if(c4[2] == 'D') b=2;
  if(c4[2] == 'C') b=3;
  if(c4[2] == 'B') b=4;
  if(c4[2] == 'A') b=5;
  if(a==1 && b==2) i3=1;
  if(a>2 && b>2) i3=1;
  if (a == b - 1 || a == b + 1)
  {
      i4 = 1;
  }
  else{
    i4 = 0;
  }
 }
 cout<<i1<<i2<<i3<<i4;
 return 0;
}

