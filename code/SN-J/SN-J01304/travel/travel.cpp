#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c)
	{
		cout<<"0";
	}
	else
	{
		cout<<"1";
	}
	if(b==d)
	{
		cout<<"1"; 
	}
	else
	{
		cout<<"0";
	} 
	cout<<"00";
	return 0;
} 
