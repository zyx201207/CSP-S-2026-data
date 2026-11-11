#include <bits/stdc++.h>
using namespace std;
string a,b;
char a1,a2,a3;
char b1,b2,b3;
bool find(char a,char b);
bool f(char a,char b);
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a ;
	cin >> a1 >> a2 >> a3;
	cin >> b;
	cin >> b1 >> b2 >> b3;
	if(a==b)
		cout<<"1";
	else
		cout<<"0";
	if(a1==b1&&a2==b2&&a==b)
		cout<<"1";
	else
		cout<<"0";
	if(a1==b1&&a2==b2&&a==b&&find(a3,b3)==1)
		cout<<"1";
	else
		cout<<"0";
	if(a1==b1&&a2==b2&&a==b&&find(a3,b3)==true&&f(a3,b3)==true)
		cout<<"1";
	else
		cout<<"0";
	return 0;
} 
bool find(char a,char b)
{
	if(a>'C'&&b>'C')
		return 1;
	else if(a<='C'&&b<='C')
		return 1;
	else
		return 0;
}
bool f(char a,char b)
{
	if(a-1==b||a+1==b||b-1==a||b+1==a)
		return 1;
	else
		return 0;
}
