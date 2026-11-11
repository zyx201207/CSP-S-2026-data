#include <bits/stdc++.h>
using namespace std;
int n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	int a[n];
	for (int i = 0;i < n;i++)
	    cin >> a[i];
	int sum=0;
	for (int i = 2;i < n;i++)
	{
		int k = 0,s = 1;
		for(int j=i-1;j>=0;j--)
		{
			k+=a[i] - a[j];
			s++;
			if(k>m)
			    break;
			if (s>sum)
			{
				sum=s;
			}
			
		}
	}
	cout << sum;
	return 0;
 } 
