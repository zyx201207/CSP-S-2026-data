#include<bits/stdc++.h>
using namespace std;
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  
  string c1,s1,c2,s2;
  cin>>c1>>s1>>c2>>s2; 
  if(c1==c2)cout<<1;
    else 
	{
	 cout<<"0000";
	 return 0;
	}
  if(s1[1]==s2[1])cout<<1;
       else cout<<0;
  for(int i=2;i<=2;i++)
   {
	if((s1[1]==s2[1])&&((abs(s1[i]-s2[i]))<=2)&&((s1[i]=='A'||s1[i]=='B'||s1[i]=='C')&&(s2[i]=='A'||s2[i]=='B'||s2[i]=='C')))
	     cout<<1;
    else if((s1[1]==s2[1])&&((abs(s1[i]-s2[i]))<=2)&&((s1[i]=='F'||s1[i]=='D')&&(s2[i]=='D'||s2[i]=='F')))
         cout<<1;
    else cout<<0;
   }
  for(int i=2;i<=2;i++)
   {
	if((s1[1]==s2[1])&&((abs(s1[i]-s2[i]))==1)&&(s1[i]!='D'&&s2[i]!='C')&&(s1[i]!='C'&&s2[i]!='D'))
   	 {
   	   cout<<1;
	   return 0;	
	 }
   	else 
	 {
	   cout<<0;
	   return 0;
	 }
   } 
  
  fclose(stdin);
  fclose(stdout);
  return 0;
} 
