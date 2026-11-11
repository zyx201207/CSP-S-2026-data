#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  char c[6],s[6];
  int d[4];
  for(int i=1;i<=2;i++)
  {
   cin>>c[i];
  } 
   for(int i=1;i<=2;i++)
  {
   cin>>s[i];
  } 


  	if(c[1]==s[1])
  	{ d[1]=1;
	 
	  }
	   else
	   {
	    d[1]=0;
	   }
	   
	   if(c[2]+1==s[2]||c[2]-1==s[2])
	  {
	   d[2]=1;
	   d[4]=1;
	  }
	  else
	  {
	  d[2]=1;
	  d[4]=0;
	  }
	  if(c[2]!='01C'&&s[2]!='01D'||c[2]!='01D'&&s[2]!='01C')
	  {
	  	d[3]=1;
	  	d[4]=1;
	  }
	  else
	  {
	  d[3]=0;
	  d[4]=0;
	  }
	  
	  
	  for(int i=1;i<=4;i++)
	  {
	   cout<<d[i]<<endl;
	  }
	  
	  
  return 0;
}
  
