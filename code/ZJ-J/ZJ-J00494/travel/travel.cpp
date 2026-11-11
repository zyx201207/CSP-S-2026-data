#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		return 0;
	}
	string row1=s1.substr(0,2);
	string row2=s2.substr(0,2);
	char col1=s1[2];
	char col2=s2[2];
	if(col1=='F') col1='E';
	if(col2=='F') col2='E';
	if(row1 != row2)
	{
		cout<<"1000"<<endl;
		return 0;
	}
	if((col1>='A' && col1<='C' && col2>='A' && col2<='C') || (col1>='D' && col1<='E' && col2>='D' && col2<='E'))
	{
		if((col1-col2==1) || (col2-col1==1))
		{
			cout<<"1111"<<endl;
		}
		else cout<<"1110"<<endl;
	}
	else
	{
		cout<<"1100"<<endl;
	}
	return 0;
}
