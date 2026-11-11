#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char s11=s1[2],s22=s2[2];
	int n=0,a,c,s1num=s1[0]-'0'+s1[1]-'0',s2num=s2[0]-'0'+s2[1]-'0';
	
	if(c1[0]==c2[0] && c1[1]==c2[1])
		cout<<"1";
	else
		cout<<"0";
	
	
	if(s1num==s2num){
		cout<<"1";	
		n=1;
	}
	else
		cout<<"0";
		
	
	if(n==1){
		if(s11=='A' && s22!='D')
			if(s22!='F'){
				cout<<"1";
				a=1;
			}
		else if(s11=='B' && s22!='D')
			if(s22!='F'){
				cout<<"1";
				a=1;
			}
		else if(s11=='C' && s22!='D')
			if(s22!='F'){
				cout<<"1";
				a=1;
			}
		else if(s11=='D' && s22=='F'){
			cout<<"1";
			a=1;
		}
		else if(s11=='F' && s22=='D'){
			cout<<"1";
			a=1;
		}
	}
	if(a!=1)
		cout<<"0";
		
		
	if(s11==s22)
	{
		if(s1num+1==s2num){
			cout<<"1";
			c=1;
		}
		else if(s2num+1==s1num){
			cout<<"1";
			c=1;
		}
	}
	else if(s1num==s2num)
	{
		if(s11-'0'+1+'0'==s22 )
			if(s11!='C')
			{
				cout<<"1";
				c=1;
			}
		else if(s22-'0'+1+'0'==s11 )
			if(s22!='C')
			{
				cout<<"1";
				c=1;
			}
	}
	if(c!=1)
	{
		cout<<"0";
	}
	return 0;
}