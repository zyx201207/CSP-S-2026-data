#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2,s;
string ans="0000";
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	s+=s1[2];
	s+=s2[2]; 
	if(c1==c2)
	{
		ans[0]='1';
	}
	else
	{
		cout<<"0000";
		return 0;
	} 
	if((s1[0]+s1[1])==(s2[0]+s2[1]))
	{
		ans[1]='1';
		if(s=="AB"||s=="BA"||s=="BC"||s=="CB"||s=="AC"||s=="CA")
		{
			ans[2]='1';
		}
		if(s=="FD"||s=="DF"||s=="CB"||s=="BC"||s=="BA"||s=="AB")
		{
			ans[3]='1';
		}
	}
	cout<<ans;
	return 0;
} 
