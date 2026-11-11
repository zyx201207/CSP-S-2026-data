#include <bits/stdc++.h>
using namespace std;
int main
{
	freopen("and","in");
	int m,n,a[10005],b[1005];
	for(int i=0;i<=n;i++)
	{
		cin>>a[i];
	}
		for(int i=0;i<=n;i++)
	{
		b[i]=a[i]||a[i+1];
	}
	sort(b[0],b[n+1]);
	
	for(int i=0;i<=m-1;i++)
	{
		cout>>b[i];
	}

	
	
	
	
}
