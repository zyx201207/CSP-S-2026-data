#include<bits/stdc++.h>
using namespace std;
string c[5];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=1;i<=4;i++)
	{
		string t;
		cin >> t;
		c[i]=t;
	}
	if(c[1]==c[2])
	{
		cout << "1111";
	}
	else
	cout << "0000";
	return 0;
} 
