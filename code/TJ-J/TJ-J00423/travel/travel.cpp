#include<iostream>
using namespace std;
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1;
		char a1=s1[0];
		char a2=s1[1];
		char b1=s2[0];
		char b2=s2[1];
		if(a1+a2==b1+b2)
		{
			cout<<"1" ;
			char c=s1[2];
			char d=s2[2];
			if((c=='A' && (d=='B' || d=='C')) || (c=='B' && (d=='A' || d=='C')) || (c=='C' && (d=='B' || d=='A')) || (c=='D' && d=='F') || (c=='F' && d=='D'))
			{
				cout<<1;
				if((c=='A' && d=='B') || (c=='B' && (d=='C' || d=='A') )|| (c=='D' && d=='F') || (c=='F' && d=='D'))			
					cout<<"1";
				else 
					cout<<"0";
			} 
			else 
			{
				cout<<"00"; 
			}
		}
		else 
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	} 
	return 0;
 } 

