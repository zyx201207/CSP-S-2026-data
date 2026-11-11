#include<iostream>
#include<string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<1; 	
	}
	else
	{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int pai1=(s1[0]-'0')*10+(s1[1]-'0');
	int pai2=(s2[0]-'0')*10+(s2[1]-'0');
	if(pai1==pai2) cout<<1;
	else 
	{
		cout<<0<<0<<0;
		return 0;
	}
	char zw1=s1[2],zw2=s2[2];
	if(zw1<='C'&&zw2<='C')
	{
		cout<<1;
		if(zw1=='B'||zw2=='B')
		{
			cout<<1;
		}
		else cout<<0;
	}
	else if(zw1>='D'&&zw2>='D')
	{
		cout<<1<<1;
		
	}
	else 
	{
		cout<<0<<0;
	}
	return 0;
 } 
