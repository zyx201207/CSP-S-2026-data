#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s,f;
	int a,b,c,d; 

	cin>>a>>b>>s>>c>>d>>f;
	if(a!=c)
	{
		cout<<"0000";
		return 0;
	}
	if(a==c)
	{
		cout<<"1";
	}//是否同车厢 
	 if(b!=d)
	{
		cout<<"000";
		return 0;
	}
	if(b==d)
	{
		cout<<"1";
	}//判断是否同排 
	if(s=="F"||s=="D" && f=="D"||f=="F")
	{
		cout<<"1";
		return 0;
	}
	if(s=="A"||s=="B" ||s=="C" && f=="A"||f=="B"|| f=="C")
	{
		cout<<"1";
	}//判断是否同侧 */
	else {
		cout<<"0";
	}
	if(s=="A"&&f=="B")
	{
		cout<<"1";
		return 0;
	}
	if(s=="B"&&f=="A"||f=="C")
	{
		cout<<1;
		return 0;
	}
	if(s=="C"&&f=="B")
	{
		cout<<1;
		return 0;
	}
	else{
		cout<<"0";
	}
	return 0;
}
