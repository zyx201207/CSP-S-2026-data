#include <bits/stdc++.h>
using namespace std;
int gs[100010];
char a[100010];
int main()
{
	int n;
	cin>>n;
	for(int i = 1;i<=n;i++)
	{
		cin>>gs[i]>>a[i];
	}
	int q = 1,p = n,cnt =0;
	while(q<p)
	{
		if(a[q]!=a[p])
		{
			cnt++;
			
		}
		if(gs[q]==1)
		{
			q++;
		}
		else
		{
			gs[q]--;
		}
		if(gs[p]==1)
		{
			p--;
		}
		else
		{
			gs[p]--;
		}
	} 
	cout<<cnt; 
	return 0;
} 
