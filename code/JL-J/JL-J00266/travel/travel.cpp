#include<bits/stdc++.h>
using namespace std;
#define N 1110
char a[N],b[N],c[N],d[N];
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  cin>>a>>b>>c>>d;
  if(a[1]==c[1]&&a[0]==c[0])
  {
	 cout<<"1";
  }
  else  if(a[1]!=c[1]||a[0]!=c[0])
  {
	 cout<<"0000";
	 return 0;
  }
  if(b[0]==d[0]&&b[1]==d[1])
  {
	 cout<<"1";
  }
  else  if(b[0]!=d[0]||b[1]!=d[1])
  {
	  cout<<"000";
	  return 0;
  }
   if((b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F'))
	{
	cout<<"1";
	}
	else if((b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='B'||d[2]=='A')))
	{
	cout<<"1";
	}
	else if((d[2]=='A'&&(b[2]=='B'||b[2]=='C'))||(d[2]=='B'&&(b[2]=='A'||b[2]=='C'))||(d[2]=='C'&&(b[2]=='B'||b[2]=='A')))
	{
	cout<<"1";
	}
	else
	{
	cout<<"0";
	}
	if((b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F'))
	{
	cout<<"1";
	}
	else if((d[2]=='B'&&(b[2]=='C'||b[2]=='A'))||(d[2]=='C'&&(b[2]=='B'))||(d[2]=='A'&&b[2]=='B'))
	{
	cout<<"1";
	}
	else
	{
	cout<<"0";
	}
	
 return 0;
}
