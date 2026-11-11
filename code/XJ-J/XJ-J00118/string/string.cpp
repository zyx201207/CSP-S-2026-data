#include <bits/stdc++.h>
using namespace std;
int main()
{
   freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  long long n,g[34],f=0,h=0;
  char a[35];
  char b[4500];
  cin>>n;
  for(int i=1;i<=n;i++)
  {
    cin>>g[i];
    cin>>a[i];
  }
  for(int i=1;i<=n;i++)
  {
  	for(int y=1;y<=g[i];y++)
  	{  f++;
	  b[f]=a[i];
	  }	
  }
   if(f%2==1)
   {
   	f=f+1;
   }
   
   for(int i=1;i<=f;i++)
   {
   	if(b[i]!=b[f-i+1])
   	{
	   h++;
	   b[f-i+1]=b[i];
	   }
	
   }
   cout<<h<<endl;
}
