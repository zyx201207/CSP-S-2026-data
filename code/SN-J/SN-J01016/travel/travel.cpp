#include<iostream>
int abs(int x)
{
	if(x<0)return -x;
	return x;
	
}
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,d1,c2,d2;
	char s1,s2;
	cin>>c1>>d1>>s1>>c2>>d2>>s2;
	if(c1==c2)
	{
		cout<<'1';
		if(d1==d2)
		{
			cout<<'1';
			if(((s1=='A'||s1=='B'||s1=='C')&&(s2=='A'||s2=='B'||s2=='C'))||((s1=='D'||s1=='F')&&(s2=='D'||s2=='F')))
			{
				cout<<'1';
			}
			else cout<<'0';
			
		}
		else cout<<"00";
		
		//ÏàÁÚ
		if(s1==s2)
		{
			if(abs(d1-d2)==1)cout<<'1';
			else cout<<0;
		 } 
		 else
		 {
		 	if(s1=='F')s1='E';
		 	if(s2=='F')s2='E';
		 	if(d1==d2&&abs(s1-s2)==1&&!((s1=='C'&&s2=='D')||(s1=='D'&&s2=='C')))cout<<"1";
		 	else cout<<0;
		 	
		 }
	}
	else cout<<"0000";
	
}
