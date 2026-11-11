#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s[4] = {};
	for(int i = 1;i<=4;i++)
	{
		cin>>a[i]; 
		if(a[0] == a[2] && (a[1] - a[3] == 1 || a[3] - a[1] == 1)
		{
			cout<<"1111";
		}
		if(a[0] == a[2] && (a[1]-a[3] > 1 || a[3]-a[1] >1))
		{
			cout<<"1010";
		}
		if(a[0] != a[2] && (a[1]) - a[3]  == 1 || a[3] - a[1] == 1)
		{
			cout<<"0101";
		}
		
		else
		{
			cout<<"0000";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
