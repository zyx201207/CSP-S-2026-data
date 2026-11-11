#include<bits/stdc++.h>
using namespace std;
bool lhl(string s1,string s2)
{
	bool a=0,b=0;
	if(s1[2]=='D'||s1[2]=='E') a=1;
	if(s2[2]=='D'||s2[2]=='E') b=1;
	if(a==b) return true;
	else return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2) cout<<1;
    else
    {
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"000";
		return 0;
	}
	if(lhl(s1,s2)) cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if((s1[2]=='C'&&s2[2]=='A')||(s2[2]=='C'&&s1[2]=='A')) cout<<0;
	else cout<<1;
	return 0;
}
