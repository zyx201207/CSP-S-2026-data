#include<bits/stdc++.h>
using namespace std;
const string L="ABC";
const string R="DF";
string c1,s1,c2,s2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(nullptr)->sync_with_stdio(false);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<"1";
	}
	else
	{
		cout<<"000";
		return 0;
	}
	if((L.find(s1[2])!=-1&&L.find(s2[2])!=-1)||(R.find(s1[2])!=-1&&R.find(s2[2])!=-1))
	{
		cout<<"1";
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs((int)(L.find(s1[2])-L.find(s2[2])))==1||(R.find(s1[2])!=-1&&R.find(s2[2])!=-1))
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
	return 0;
}