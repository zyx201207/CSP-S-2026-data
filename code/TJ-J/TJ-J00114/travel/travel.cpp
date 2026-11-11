#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w".stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	
	if(c1==c2)
	{
		cout << "1";
		//cout << "!";
	}
	else
	{
		cout << "0000";
		return 0;
	}
	int l1=0,l2=0;
	for(int i=0;i<=1;i++)
	{
		int x=s1[i]-'0';
		int y=s2[i]-'0';
		l1*=10;
		l2*=10;
		l1+=x;
		l2+=y;
	}
	char seat1=s1[2];
	char seat2=s2[2];
	if(l1==l2)
	{
		cout << "1"; 
		//cout << "#";
		//(seat1>='A' && seat1<='C' && seat2>='A' && seat 2<='C')||(seat1>='D' && seat1<='F' && seat2>='D' && seat2<='F')
		if(abs(seat1-seat2)<=2 && !(seat1=='C' && seat2=='D' || seat2=='C' && seat1 =='D'))
		{
		    cout << "1";
			if(abs(seat1-seat2)==1)
			    cout << "1";
		    else if((seat1=='D'&& seat2=='F') || (seat1=='F'&& seat2=='D'))
			    cout << "1" << "\n";
			else
			    cout << "0" << "\n";	
		}	
		else
		    cout << "00" << "\n";
	}
	else
	{
		if(c1==c2)
		{
			cout << "000" << "\n";
		}
		else
		{
			cout << "0000" << "\n";
		}
	}
	return 0;
}




















 































