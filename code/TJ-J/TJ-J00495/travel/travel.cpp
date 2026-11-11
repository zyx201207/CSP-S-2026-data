#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char c[2];
    char s[3];
    char d[2];
    char q[3];
    cin>>c>>s>>d>>q;
    if(c[0]==d[0]&&c[1]==d[1])
    {
        cout<<"1";
    }
   else
   {
       cout<<"0";
   }
  if(s[0]=q[0]&&s[1]==q[1])
  {
    cout<<"1";
  }
 else
 {
     cout<<"0";
 }
 if(c[0]==d[0]&&c[1]==d[1]&&s[0]==q[0]&&s[1]==q[1])
 {
     cout<<"0";
 }
 else
 {
     cout<<"1";
 }
 if(c==d&&s[0]==q[0]&&s[1]==q[1]&&s[2]-q[2]==1||q[2]-s[2]==1)
 {
     cout<<"1";
 }
 else

 {
     cout<<"0";
 }


    return 0;
}
