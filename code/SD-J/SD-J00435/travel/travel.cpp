#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
string c1,s1,c2,s2;
bool pd()
{
	int i,j;
	for(i=0;i<s1.size()-1;i++)
	  {
	  	if(s1[i]!=s2[i])
	  	  return false;
	  }
	return true;
}
bool l1,l2,l3,l4;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	  {cout<<"0000";return 0;l1=false;}
	else
	  {cout<<"1";l1=true;}
	if(pd())
	  {
	    cout<<"1";
	    l2=true;
	    if(s1[s1.size()-1]=='D' || s1[s1.size()-1]=='F')
	      {
	      	if(s2[s2.size()-1]=='D' || s2[s2.size()-1]=='F')
	      	  {cout<<"1";l3=true;l4=true;}
	      	else
	      	  {cout<<"0";l3=false;l4=false;}
		  }
		else
		  {
		  	if(s1[s1.size()-1]=='B' || s1[s1.size()-1]=='A' || s1[s1.size()-1]=='C')
		  	  {
		  	  	if(s2[s2.size()-1]=='B' || s2[s2.size()-1]=='A' || s2[s2.size()-1]=='C')
			      {
				    cout<<"1";
					l3=true;
					if(s1[s1.size()-1]+1==s2[s2.size()-1] || s1[s1.size()-1]-1==s2[s2.size()-1])
					  {
					  	l4=true;
					  }
					else
					  l4=false;
				  }
			    else
			      {cout<<"0";l3=false;l4=false;}
			  }
		  }
	  }
	else
	  {cout<<"00";l2=false;l3=false;l4=false;}
	if(l1 && l2 && l3 && l4)
	  {
	  	cout<<"1";
	  }
	else
	  {
	  	cout<<"0";
	  }
	return 0;  
}
