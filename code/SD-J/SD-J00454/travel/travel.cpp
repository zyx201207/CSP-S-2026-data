#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,n1,s2,n2;
	cin>>s1>>n1>>s2>>n2;
	if(s1==s2)
	{
		cout<<'1'; 
	 } 
	 else
	 {
	 	cout<<"0000";
	 	return 0;
	 } 
	if((n1[0]+n1[1])==(n2[0]+n2[1]))
	{
		cout<<'1';
	}
	else
	{
		cout<<"000";
		return 0;
	}
	int num1,num2;
	if(n1[2]>='A'&&n1[2]<='C')
	{
		num1++;
	}
	else
	{
		num2++;
	}
	if(n2[2]>='A'&&n2[2]<='C')
	{
		num1++;
	}
	else
	{
		num2++;
	}
	if(num1==2||num2==2)
	{
		cout<<'1'; 
	}
	else
	{
		cout<<"00";
		return 0;
	}
	if(abs(0+n1[2]-n2[2])==1)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
	}
	cout<<endl;
	return 0;
 } 
