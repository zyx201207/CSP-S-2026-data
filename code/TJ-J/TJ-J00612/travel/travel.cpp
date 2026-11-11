#include<bits/stdc++.h>
using namespace std;
string r;
string r1;
string s;
string s1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> r >> r1 >> s >> s1;
	bool flag=true;
	if(r==s)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
		flag=false;
	}
	if(s1[0]==r1[0]&& s1[1]==r1[1] && flag==true)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
		flag=false;
	}
	int a=s1[2]-65;
	int b=r1[2]-65;
	if(((a<3 && b<3) || (a>=3 && b>=3))&& flag==true)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
		flag=false;
	}
	int c=0;
	if(a>b)
	{
		c=a-b;
	}
	else
	{
		c=b-a;
	}
	if(c==1 && !((a==3 && b==2) || (a==2 && b==3)) && flag==true)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
//	cout << a;
	return 0;
}
