#include <bits/stdc++.h>
using namespace std;
int n,m;
string p,a;
int sum;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n; 
	for (int i=1;i<=n;i++)
	{
		cin>>m>>p;
		for (int j=1;j<=m;j++)
		{
		a+=p;
		}
	}
	
	int l=0,r=a.length()-1;
	
	while (l!=r)
	{
		if (a[l]!=a[r])
		{
			sum++;
		}
		l++;
		r--;
	}
	cout<<sum;
	
	return 0;
}
