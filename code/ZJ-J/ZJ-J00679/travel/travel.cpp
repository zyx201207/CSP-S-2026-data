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
	string h1=s1.substr(0,2),h2=s2.substr(0,2);
	if(h1!=h2)
	{
		cout<<"1000";
		return 0;
	}
	char l=s1[2],r=s2[2];
	if(((l-65)<=2) xor ((r-65)<=2)==1)
	{
		cout<<"1100";
		return 0;
	}
	if(!(abs(l-r)==1||l+r==138))
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}