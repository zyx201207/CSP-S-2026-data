#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int a[10001];
	int m,n,s=1;
	cin>>m>>n;
	for(int i=0;i<m;i++)
	{
		cin>>a[i];
	}
    sort(a+0,a+n);
	for(int i=0;i<m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[j]-a[i]<=m)
			{
				s++;
				m=m-(a[j]-a[i]);
			}
		}
	}
	cout<<s;
	return 0;


}
