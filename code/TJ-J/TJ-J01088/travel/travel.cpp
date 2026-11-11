#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	int c1,c2;
	int cnt=0;
	string s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1!=c2)
	{
		cout << "0000";
		return 0;
	}
	if(c1==c2)
	{
		cout << 1;
		cnt++;
	}
	else 
	{
		cout << 0;
	}
	int number1 = (s1[0]-'0')*10+(s1[1]-'0');
	int number2 = (s2[0]-'0')*10+(s2[1]-'0');
	bool b=false;
	if(number1==number2)
	{
		cout << 1;
		cnt++;
		b=true;
	}
	else
	{
		cout << 0;
	}
	if(b==1&&s1[2]<='C'&&s2[2]<='C'||s1[2]>='D'&&s2[2]>='D'&&b==1)
	{
		cout << 1;
		cnt++;
	}
	else
	{
		cout << 0;
	} 
	if(cnt==3&&abs(s1[2]-s2[2])==1)
	{
		cout << 1;
	}
	else cout << 0;
	
	
	return 0;
}
