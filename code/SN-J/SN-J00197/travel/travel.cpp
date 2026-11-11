#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a[14]; 
	for(int i=1;i<=14;i++)
	{
		cin>>a[i];
	}
	if(a[2]==a[9]&&a[1]==a[8])
	{
		cout<<1; 
		if(a[4]==a[11]&&a[5]==a[12])
		{
			cout<<1;
			if(a[6]+18==a[13])
			{
				cout<<1<<1;
			}
			else
			{
				cout<<0;
			} 
		}
		else
		{
			cout<<0;
		}
	}
	else
	{
		for (int i=1;i<=4;i++)
		{
			cout<<0;
		}
	}
	return 0;
}

