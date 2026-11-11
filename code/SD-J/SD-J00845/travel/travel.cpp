#include <bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;
int a[0],b[0];
int main()
{
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if(c1==c2&&s1==s2)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	if(c1==c2&&s1==s2&&a[0]!=b[0]&&a[0]==b[0])
	{
		cout <<"1";
	}
	else
	{
		cout << "0" ;
	}
	if(a[0]-b[0]==1&&a[0]-b[0]==0&&a[0]-b[0]!=2)
	{
		cout << "1";
	}
	else
	{
		cout << "0";
	}
	return 0;
}
