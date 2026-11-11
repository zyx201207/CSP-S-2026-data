#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) 
	{
		cout<<"1";
		char a=s1[0],b=s1[1];
		char c=s2[0],d=s2[1];
		if(a==c&&b==d) 
		{
			cout<<"1";
			char e=s1[2],f=s2[2];
			if(((e=='A'&&(f=='B'||f=='C'))||(e=='B'&&(f=='A'||f=='C'))||(e=='C'&&(f=='A'||f=='B')))||((e=='D'&&(f=='F'))||(e=='F'&&f=='D'))) 
			{
				cout<<"1";
				if(((e=='A'&&f=='B')||(e=='B'&&f=='A')||(e=='B'&&f=='C')||(e=='C'&&f=='B')||(e=='D'&&f=='F')||(e=='F'&&f=='D')))
				{
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else 
	{
		cout<<"0000";
	}
}
