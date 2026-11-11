#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int main()
{
 long long n,sum1,x=0;
 string a,b;
 freopen("string.in","r",stdin);
 freopen("string.out","w",stdout);
 cin>>n;
 for (int i = 1; i <= n;i++)
 {
  cin>>sum1>>a;
  for ( int i = 1;i <= sum1; i++)
  {
      b+=a;
  }
  if (n % 2 == 0)
  {
      for (int i = 0;i != n-1;i++)
      {
           if (b[i] =! b[n-1-i])
           {
               x+=1;
           }
           n-=1;
      }
  }
  else
  {
      for (int i = 0;i != n;i++)
      {
          if (b[i] =! b[n-1-i]) x++;
           n-=1;
      }
  }
 }
 cout<<x;
 return 0;
}

