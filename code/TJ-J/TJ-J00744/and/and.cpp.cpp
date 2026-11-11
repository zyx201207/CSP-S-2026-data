#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int  n,m,cnt=0;
	int a[200005];
	int t[200005];
	cin>>n>>m;
	int b=n;
	for (int i=0;i<=b;i++)
	{
		cin>>a[i];
	}
	t[0]=a[0];
	for(int i=0;i<=b;i++)
	{
		if(t[i]<=a[i+1])
		{
			t[i+1]=a[i+1];
		}
	}
	cnt=t[1];
	for(int i=2;i<=m;i++)
	{
		cnt=t[i]&cnt;
	}
	cout<<cnt;
	
	return 0;
} 
