#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,c1;
	string s,s1;
	cin>>c>>s>>c1>>s1;
	if(c==c1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	int a = s[0]+s[1]-'0';
	int b = s1[0]+s1[1]-'0';
	if(a==b)
	{
		cout << 1;
	}
	else
	{
	cout << 0;
	}
	char w = s[2];
	char w1=s1[2];
	if(w == 'A'&&w1=='B'||w == 'A'&&w1=='C'||w == 'B'&&w1=='A'||w == 'B'&&w1=='C'||w == 'C'&&w1=='A'||w == 'C'&&w1=='B'||w == 'D'&&w1=='F'||w == 'F'&&w1=='D')
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
	if(w == 'A'&&w1=='B'||w == 'B'&&w1=='A'||w == 'B'&&w1=='C'||w == 'C'&&w1=='B'||w == 'D'&&w1=='F'||w == 'F'&&w1=='D')
	{
		cout << 1;
	}
	else
	{
	cout <<0;
}
	return 0;
}
