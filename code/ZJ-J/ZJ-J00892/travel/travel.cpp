#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2)	cout<<1;
	else
	{
		cout<<"0000";
		return 0;
	}
	int num1=0,num2=0;
	for(int i=0;i<2;i++)
	{
		int temp=s1[i]-'0';num1=num1*10+temp;
		int temp2=s2[i]-'0';num2=num2*10+temp2;
	}
	if(num1==num2)	cout<<'1';
	else
	{
		cout<<"000";
		return 0;
	}
	int ce1=s1[2]-'A',ce2=s2[2]-'A';
	if(ce1>ce2)		swap(ce1,ce2);
	if(ce1==0||ce1==1)
	{
		
		if(ce2<=2)	cout<<1;
		else
		{
			cout<<"00";return 0;
		}
		if(ce2==ce1+1)	
		{
			cout<<1;
		}
		else	cout<<0;
	}
	if(ce1>=3&&ce1<=4)
	{
		if(ce2<=5&&ce2>=4)	cout<<1;
		else
		{
			cout<<"00";return 0;
		}
		if(ce2=ce1+1)	cout<<1;
		else	cout<<0;
	}
	if(ce1==2||ce1==5)	cout<<"00";
	return 0;
}