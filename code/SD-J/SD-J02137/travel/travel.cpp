#include<bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	
	//
	bool b=1;
	for(int i=0;i<2;i++)
	{
		if(s1[i]!=s2[i]) b=0;
	}
	if(b) cout<<1;
	else cout<<0;
	
	//
	bool b2=0;
	if(b==1)
	{
		b2=1;
		if(s1[3]<='C')
		{
			if(s2[3]<='C') cout<<1;
			else 
			{
				cout<<0;
				b2=0;
			}
		}
		else 
		{
			if(s2[3]>'C') cout<<1;
			else 
			{
				cout<<0;
				b2=0;
			}
		}
	}
	else cout<<0;
	
	
	
	//
	if(b&b2)
	{
		if(abs(s1[2]-s2[2])==1) cout<<1;
		else cout<<0;
	}
	else cout<<0;
//	cout<<' '<<b<<' '<<b2;
 } 

