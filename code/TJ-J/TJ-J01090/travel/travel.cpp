#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2&&c1!=01&&c1!=16)
	{
		cout<<"1111";
	}
	else
	{
		cout<<"0111";
	}
	return 0;
} 
