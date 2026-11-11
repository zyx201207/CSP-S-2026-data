#include<bits/stdc++.h>
using namespace std;
string b1,b2;
int a1,a2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>b1>>a2>>b2;
	if(a1==a2) 
	{
	cout<<'1';
	if(b1[0]==b2[0] and b1[1]==b2[1]) 
	{
	cout<<'1';
	if((b1[2]-'A'>=0 and b1[2]-'A'<3 and b2[2]-'A'>=0 and b2[2]-'A'<3) or (b1[2]-'A'>=3 and b1[2]-'A'<5 ))
	{
		cout<<'1';
		if((b1[2]-'A'+1) == (b2[2]-'A') or (b1[2]-'A'-1) == (b2[2]-'A')) cout<<'1';
		else cout<<'0';
	}
	else cout<<"00";
	
	}
	else cout<<"000";
}
	else cout<<"0000";
return 0;
}
