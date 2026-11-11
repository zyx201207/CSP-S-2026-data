#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string cara,carb,posa,posb;
	bool flag=false;
	bool flagt=false;
	bool flagth=false;
	int numa,numb;
	char aa,bb;
	cin >> cara>>posa>>carb>>posb;
	if(cara==carb)
	{
		cout << '1';
		flag=true;
	}
	else cout << '0';
	numa=(posa[0]-'0')*10+(posa[1]-'0');
	numb=(posb[0]-'0')*10+(posb[1]-'0');
	aa=posa[2];
	bb=posb[2];
	if(flag&&numa==numb)
	{
		flagt=true;
		cout << '1';
	}
	else cout << '0';
	if(flagt&&((aa=='A'&&bb=='B')||(aa=='C'&&bb=='B')||(aa=='A'&&bb=='C')||(aa=='D'&&bb=='E')))
	{
		flagth=true;
		cout << '1';
	}
	else cout << '0';
	if(flagth&&((aa=='A'&&bb=='B')||(aa=='C'&&bb=='B')||(aa=='D'&&bb=='E')))cout << '1';
	else cout << '0';
	
	return 0;
	
}
