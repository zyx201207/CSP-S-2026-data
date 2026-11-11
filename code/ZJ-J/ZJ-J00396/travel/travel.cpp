#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
bool cal(char a,char b)
{
	if('A'<=a && a<='C')
	{
		if('A'<=b && b<='C') return true;
	}
	else
		if('D'==b || b=='F') return true;
	return false;
}
bool pro_cal(char a,char b)
{
	if('A'<=a && a<='C')
	{
		if(a+1==b && b+1==a) return true;
	}
	else
		if(('D'==b || b=='F') && a!=b) return true;
	return false;	
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)
	{
		cout<<"1";
		if(s2[0]==s4[0] && s2[1]==s4[1])
		{
			cout<<"1";
			if(cal(s2[2],s4[2]))
			{
				cout<<"1";
				if(pro_cal(s2[2],s4[2])) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}