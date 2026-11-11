#include<bits/stdc++.h>
#define ll long long
#define AC ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
string ac,bc,as,bs;
int main()
{
  freopen("travel.in","r",stdin);
  freopen("travel.out","w",stdout);
  AC;
  cin>>ac>>as>>bc>>bs;
  if(ac==bc)
  {
  	cout<<"1";
  	if(as[0]==bs[0] && as[1]==bs[1])
  	{
  	  cout<<"1";
  	  int a=as[2]-'A'+1,b=bs[2]-'A'+1;
  	  if( (a<=3 && b<=3) || (a>3 && b>3) )
  	  {
  	  	cout<<"1";
  	  	if(abs(a-b)==1)
  	  	{
  	  	  cout<<"1";
		}
		else
		{
		  cout<<"0";
		}
	  }
	  else
	  {
	  	cout<<"00";
	  }
	}
	else
	{
	  cout
	  <<"000";
	}
  }
  else
  {
  	cout<<"0000";
  }
  return 0;
}
