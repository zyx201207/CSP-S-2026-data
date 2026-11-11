#include<bits/stdc++.h>
using namespace std;
int n,sum,a[200007];
char c[200007];
string s,ds;
int main()
{
  freopen("string.in","r",stdin);
  freopen("string.out","w",stdout);
  
  cin>>n;
  for(int i=1;i<=n;i++)
   {
    cin>>a[i]>>c[i];	
  	cin>>s;
	int x;
  	x=a[i];
	for(int j=1;j<=x;j++)
	  s=c[i]+c[i+1];	
   }
  for(int i=s.size();i>=0;i--)
   {
   	cin>>ds;
	ds=s; 	
   }		
  if(ds==s)cout<<0;
   else 
   {
  	if(s.size()%2==0)cout<<s.size()/2; 
   } 
  
  fclose(stdin);
  fclose(stdout);
  return 0;
} 

