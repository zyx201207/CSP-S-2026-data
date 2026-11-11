#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[200000+5];
	int s=1;
	int b[200000+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	while(s<m)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]<a[i-1])
			{
				swap(a[i],a[i-1]);
			}
		}
		b[s]=a[n];
		s++;
		n--;
	}
	int z=b[1];
	for(int i=2;i<=s;i++)
	{
		z=z&b[i];
	}
	cout<<z;
	return 0;
}
