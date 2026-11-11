#include<bits/stdc++.h>
using namespace std;
int a[5];
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  string cr,r,cx,x;
  cin>>cr>>r>>cx>>x;
  if(cr==cx)
  {
    a[1]=1;
    if(r[0]==x[0])
    {
      if(r[1]==x[1])
      {
        a[2]=1;
        if(r[2]='A' ||r[2]=='B'||r[2]=='C')
        {
          if(x[2]=='A'||x[2]=='B'||x[2]=='C')
          {
            a[3]=1;
            if(r[2]=='A',x[2]=='B'||r[2]=='B',x[2]=='C'||r[2]=='B',x[2]=='A'||r[2]=='C',x[2]=='B')
              a[4]=1;
            else
              a[4]=0;
          }
        }
        else if(r[2]=='D'||r[2]=='F')
        {
          if(x[2]=='D'||x[2]=='F')
          {
            a[3]=1;
            a[4]=1;
          }
          else
          {
            a[3]=0;
            a[4]=0;
          }
        }
        else
        {
          a[3]=0;
          a[4]=0;
        }
      }
      else
      {
        a[2]=0;
        a[3]=0;
        a[4]=0;
      }
    }
    else
    {
      a[2]=0;
      a[3]=0;
      a[4]=0;
    }
  }
  else
  {
    a[1]=0;
    a[2]=0;
    a[3]=0;
    a[4]=0;
  }
  for(int i=1;i<=4;i++)
    cout<<a[i];
  return 0;
}
