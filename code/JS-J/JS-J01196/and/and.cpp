#include <bits/stdc++.h>

using namespace std;

int b[200000];

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin >> n  >> m;
	
	for(int i=0;i<n;i++)
	{
		cin >> b[i];
	}
	
	int max=0;
	for(int i=0;i<n;i++)
	{
		if(b[i]>max)
		{
			max=b[i];
		}
	}
	
	cout << max;
	
	return 0;
}
