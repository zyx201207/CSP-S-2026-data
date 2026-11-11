#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[9500000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int h=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=1;j--)
		{
			if(a[j]-a[i]<=m)
			{
				m=m-(a[j]-a[i]);
				i++;
				h++;
			}
		} 
	}
	cout<<h;
	return 0;
}