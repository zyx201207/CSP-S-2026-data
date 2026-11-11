#include<iostream> 
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if((02<=a<=16)||a==17)
	{
		if(a==c)
		{
			cout<<"1";
		}
		else
		{
			cout<<"0";
		}
	}
	if(b==d)
	{
		cout<<"1";
	}
	else
	{
		cout<<"0";
	}
}
