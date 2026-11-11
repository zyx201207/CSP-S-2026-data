#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string cnt1,cnt2;
char  k,d;
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>c1>>s1>>c2>>s2;
  if(c1==c2)
    cout<<1;
  else
    cout<<0;
  for(int i=0;i<=s1.length()-1;i++)
  {

      if(s1[i]>='0'&&s1[i]<='9')
      {

           cnt1=s1[i];
      }
      else
      {
          k=s1[i];

      }
  }
   for(int i=0;i<=s2.length()-1;i++)
  {

      if(s2[i]>='0'&&s2[i]<='9')
      {

           cnt2=s2[i];
      }
      else
      {

          d=s2[i];
      }
  }
  if(c1==c2&&cnt1==cnt2)
    cout<<1;
  else
    cout<<0;
    if((k==d+1||d==k+1))
        cout<<1;
    else
        cout<<0;
    if((k==d+1||d==k+1)&&c1==c2&&cnt1==cnt2)
        cout<<1;
    else
        cout<<0;
  return 0;
}
