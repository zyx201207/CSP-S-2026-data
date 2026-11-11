#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	cout<<1;
	string sa="",sb="";
	sa=sa+s1[0]+s1[1];sb=sb+s2[0]+s2[1];
	if(sa!=sb)
	{
		cout<<"000";
		return 0;
	}
	cout<<1;
	sa=s1[2],sb=s2[2];
	if((sa=="A"&&sb=="B")||(sa=="B"&&sb=="C")||(sa=="B"&&sb=="A")||(sa=="C"&&sb=="B"))
	{
		cout<<"11";
		return 0;
	}
	else if((sa=="A"&&sb=="C")||(sa=="C"&&sb=="A"))
	{
		cout<<"10";
		return 0;
	}
	else if((sa=="D"&&sb=="F")||(sa=="F"&&sb=="D"))
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<"00";
		return 0;
	}
	return 0;
}