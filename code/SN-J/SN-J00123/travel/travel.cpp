#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int s1,c1;
	string s2,c2;
	cin>>s1>>s2>>c1>>c2;
	if(s1!=c1)
	{
		cout<<"0000";
		return 0;
	}
	if(s2[0]!=c2[0]||s2[1]!=c2[1])
	{
		cout<<"1000";
		return 0;
	}
	if((s2[2]=='A'&&c2[2]=='D')||(s2[2]=='B'&&c2[2]=='D')||(s2[2]=='C'&&c2[2]=='D')||(s2[2]=='A'&&c2[2]=='F')||(s2[2]=='B'&&c2[2]=='F')||(s2[2]=='C'&&c2[2]=='F')||(s2[2]=='D'&&c2[2]=='A')||(s2[2]=='D'&&c2[2]=='B')||(s2[2]=='D'&&c2[2]=='C')||(s2[2]=='F'&&c2[2]=='A')||(s2[2]=='F'&&c2[2]=='B')||(s2[2]=='F'&&c2[2]=='C')) 
	{
		cout<<"1100";
		return 0;
	}
	if((s2[2]=='A'&&c2[2]=='C')||(s2[2]=='C'&&c2[2]=='A'))
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
 
