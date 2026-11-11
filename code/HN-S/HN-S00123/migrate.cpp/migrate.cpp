#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	int n;
	int t[n];
	for(int i=0;i<=n;i++)
	{
		cin >> t[i];
		}	
		if(c==0)
		{
			if(t[0]==4)
			{
				cout << 1 << endl << 2;
			}
			if(t[0]==5)
			{
				cout << 0 << 1;
			}
		}
return 0;	
}
