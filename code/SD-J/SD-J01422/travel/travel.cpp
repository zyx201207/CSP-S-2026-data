#include <bits/stdc++.h>
using namespace std;
char a,b,c,d;
char aa,bb,cc,dd;
char aaa,bbb;
int numa,numb,numaa,numbb;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b;
	numa = (a-'0')*10+(b-'0');
	cin >> aa >> bb >> aaa;
	numaa = (aa-'0')*10+(bb-'0');
	cin >> c >> d;
	numb = (c-'0')*10+(d-'0');
	cin >> cc >> dd >> bbb;
	numbb = (cc-'0')*10+(dd-'0');
	if(numa==numb)
	{
		cout << '1';
	}
	else
	{
		cout << '0';
	}
	if(numaa==numbb&&numa==numb)
	{
		cout << '1';
	}
	else
	{
		cout << '0';
	}
	if(numaa==numbb&&numa==numb)
	{
		if(aaa=='A'&&bbb=='B'||aaa=='A'&&bbb=='C'||aaa=='B'&&bbb=='C'||aaa=='B'&&bbb=='A'||aaa=='C'&&bbb=='B'||aaa=='C'&&bbb=='A'||aaa=='D'&&bbb=='E'||aaa=='E'&&bbb=='D')
		{
			cout << '1';
		}
		else
		{
			cout << '0';
		}
	}
	else
	{
		cout << '0';
	}
	if(numaa==numbb&&numa==numb)
	{
		if(aaa=='A'&&bbb=='B'||aaa=='B'&&bbb=='C'||aaa=='B'&&bbb=='A'||aaa=='C'&&bbb=='B'||aaa=='D'&&bbb=='E'||aaa=='E'&&bbb=='D')
		{
			cout << '1';
		}
		else
		{
			cout << '0';
		}
	}
	else
	{
		cout << '0';
	}
	return 0;
} 
