#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a1,b1,a2,b2;
	cin>>c1>>s1>>c2>>s2;
	a1+=(s1[0]-'0')*10;
	a1+=s1[1]-'0';
	b1=s1[2]-'A';
	a2+=(s2[0]-'0')*10;
	a2+=s2[1]-'0';
	b2=s2[2]-'A';
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	if(a1!=a2)
	{
		cout<<"1000"<<endl;
		return 0;
	}
	if((b1<=2 && b2>2) || (b2<=2 && b1>2))
	{
		cout<<"1100"<<endl;
		return 0;
	}
	if(max(b1-b2,b2-b1)!=1)
	{
		cout<<"1110"<<endl;
		return 0;
	}
	cout<<"1111"<<endl;
	return 0;
}
